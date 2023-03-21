#include "Aircraft.hpp"
#include "ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
		case Aircraft::Eagle:
			return Textures::Eagle;

		case Aircraft::Raptor:
			return Textures::Raptor;
			
		case Aircraft::Asteroid:
			return Textures::Asteroid;
	}
	return Textures::Eagle;
}

Aircraft::Aircraft(Type type, const TextureHolder& textures)
: mType(type)
, mSprite(textures.get(toTextureID(type)))
, mBounds()
{
	mBounds = mSprite.getGlobalBounds();
	mSprite.setOrigin(mBounds.width / 2.f, mBounds.height / 2.f);
}

sf::FloatRect Aircraft::getBounds()
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

unsigned int Aircraft::getCategory() const
{
	switch (mType)
	{
		case Eagle:
			return Category::PlayerAircraft;

		default:
			return Category::EnemyAircraft;
	}
}
