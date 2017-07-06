#pragma once
#include <SFML\Audio.hpp>
#include <memory>
#include "../Graph/BarGraph.h"
#include "../Util/Utils.h"


class SortAlgorithm
{
public:
	SortAlgorithm();
	~SortAlgorithm();

	virtual void setSpeed(float speed);
	virtual void sort(std::vector<Bar> & bar) = 0;
	virtual bool isSortFinished() = 0;

	virtual void setVisual(BarGraph & barGraph);
	virtual void reset();
	virtual void setSound(sf::SoundBuffer &buffer);

protected:
	BarGraph * barGraph;
	float speed_ = 0;
	int dec = 0;
	int i = 0;
	sf::Sound algoSound;
	bool isFinished = false;
};

