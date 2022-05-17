#include <Book/World.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <Book/StringHelpers.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

World::World(sf::RenderWindow& window)
: mWindow(window)
, mWorldView(window.getDefaultView())
, mTextures() 
, mSceneGraph()
, mSceneLayers()
, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
, mScrollSpeed(-50.f)
, mPlayerAircraft(nullptr)
, mAsteroid(nullptr)
, mScore()
, mAsteroidTime()
, mTracker()
{
	loadTextures();
	buildScene();
	sf::Time elapsedTime = sf::Time::Zero;
	mScore = 10;
	mAsteroidTime = sf::Time::Zero;
	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	sf::Clock clock;
	// Scroll the world, reset player velocity
	mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());	
	mPlayerAircraft->setVelocity(0.f, 0.f);
	mPlayerAircraft->setRotation(0.f);

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	while (!mCommandQueue.isEmpty())
		mSceneGraph.onCommand(mCommandQueue.pop(), dt);
	adaptPlayerVelocity();

	// Regular update step, adapt position (correct if outside view)
	mSceneGraph.update(dt);
	updateScore();
	spawnAsteroids(dt, clock);
	adaptPlayerPosition();
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

void World::loadTextures()
{
	mTextures.load(Textures::Eagle, "../Media/Textures/Eagle.png");
	mTextures.load(Textures::Raptor, "../Media/Textures/Raptor.png");
	mTextures.load(Textures::Desert, "../Media/Textures/Space.png");
	mTextures.load(Textures::Asteroid, "../Media/Textures/Asteroid.png");
}

void World::buildScene()
{	

	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	// Prepare the tiled background
	sf::Texture& texture = mTextures.get(Textures::Desert);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add player's aircraft
	std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
	mPlayerAircraft = leader.get();
	mPlayerAircraft->setPosition(mSpawnPosition);
	mSceneLayers[Air]->attachChild(std::move(leader));

	// Left Escort
	std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Raptor, mTextures));
	leftEscort->setPosition(-80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(leftEscort));

	// Left Escort
	std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Raptor, mTextures));
	rightEscort->setPosition(80.f, 50.f);
	mPlayerAircraft->attachChild(std::move(rightEscort));

	// Asteroid
	std::unique_ptr<Aircraft> asteroid(new Aircraft(Aircraft::Asteroid, mTextures));
	mAsteroid = asteroid.get();
	mAsteroid->setPosition(320,1500);
	mAsteroid->setVelocity(50.f,50.f);
	mSceneLayers[Air]->attachChild(std::move(asteroid));
}

void World::adaptPlayerPosition()
{
	// Keep player's position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
	const float borderDistance = 40.f;

	sf::Vector2f position = mPlayerAircraft->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	mPlayerAircraft->setPosition(position);
}

void World::adaptPlayerVelocity()
{
	sf::Vector2f velocity = mPlayerAircraft->getVelocity();

	// If moving diagonally, reduce velocity (to have always same velocity)
	if (velocity.x != 0.f && velocity.y != 0.f)
		mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));

	// Add scrolling velocity
	mPlayerAircraft->accelerate(0.f, mScrollSpeed);
}

void World::updateScore()
{
	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
	if(mPlayerAircraft->getBounds().intersects(mAsteroid->getBounds()))
	{
		mAsteroid->setPosition(mWorldView.getCenter().x + random(-500.f, 500.f), viewBounds.top);
		mAsteroid->setVelocity(random(-50.f, 50.f), 50.f);
		mScore -= 1;
	}
}

int World::getScore()
{
	return mScore;
}

void World::spawnAsteroids(sf::Time elapsedTime, sf::Clock clock)
{
	mAsteroidTime += elapsedTime;
	if(mAsteroidTime > sf::seconds(2.0f)) {
		mTracker += 500;
		//std::unique_ptr<Aircraft> asteroid(new Aircraft(Aircraft::Asteroid, mTextures));
		//mAsteroid = asteroid.get();
		//mAsteroid->setPosition(320,1500);
		//mAsteroid->setVelocity(50.f,50.f);
		//mSceneLayers[Air]->attachChild(std::move(asteroid));
		mAsteroidTime = sf::Time::Zero;
	}
}

float World::random(float min, float max)
{
	srand((unsigned int)time(NULL));
	float random = ((float) rand()) / (float) RAND_MAX;
	float diff = max - min;
	float r = random * diff;
	return min + r;
}