#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

class Timer {
	bool clear = false;
public:
	template<typename T>
	void setTimeout(T function, int delay);

	template<typename T>
	void setInterval(T function, int delay);

	void stop();
};

template<typename T>
void Timer::setTimeout(T function, int delay) {
	this->clear = false;
	thread t([=]() {
		if (this->clear) return;
		this_thread::sleep_for(chrono::milliseconds(delay));
		if (this->clear) return;
		function();
	});
	t.detach();
}

template<typename T>
void Timer::setInterval(T function, int interval) {
	this->clear = false;
	thread t([=]() {
		while (true) {
			if (this->clear) return;
			this_thread::sleep_for(chrono::milliseconds(interval));
			if (this->clear) return;
			function();
		}
	});
	t.detach();
}

void Timer::stop() {
	this->clear = true;
}

int main() {
	Timer t = Timer();
	t.setInterval([&]() {
		cout << "Hey.. After each 0.7s..." << endl;
	}, 700);
	t.setTimeout([&]() {
		cout << "Hey.. After 11.5s. But I will stop the timer!"
			<< endl;
		t.stop();
	}, 11500);

	cout << "I am Timer" << endl;
	while (true);
}