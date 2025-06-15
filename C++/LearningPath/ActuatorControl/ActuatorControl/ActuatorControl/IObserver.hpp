#ifndef IOBSERVER_HPP
#define IBSERVER_HPP

class IObserver {
public:
	virtual void update(double newTemperature) = 0;
	virtual ~IObserver() = default;
};

#endif // !IOBSERVER_HPP
