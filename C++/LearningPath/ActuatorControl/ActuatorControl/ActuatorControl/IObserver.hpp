//#ifndef IOBSERVER_HPP
//#define IBSERVER_HPP
#pragma once

class IObserver {
public:
	virtual void update(double newTemperature) = 0;
	virtual ~IObserver() = default;
};

//#endif // !IOBSERVER_HPP
