#include "SortAlgorithm.h"
SortAlgorithm::SortAlgorithm()
	:barGraph(barGraph), algoSound(algoSound)
{
	
}

SortAlgorithm::~SortAlgorithm()
{

}

void SortAlgorithm::setSpeed(float speed)
{
	speed_ = speed;
}

void SortAlgorithm::setVisual(BarGraph &barGraph_)
{
	barGraph = &barGraph_;
	dec = barGraph->size();
}

void SortAlgorithm::reset()
{
	i = 0;
}

void SortAlgorithm::setSound(sf::SoundBuffer &buffer)
{
	algoSound.setBuffer(buffer);
}
