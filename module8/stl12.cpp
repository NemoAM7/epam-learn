#include<iostream>
#include<set>
#include<vector>
#include<string>

bool scheduleEvent(std::set<int>& scheduledEvents, int startTime) {
	std::cout << "Attempting to schedule an event.." << std::endl;
	auto insertResult = scheduledEvents.insert(startTime);
	if (insertResult.second) {
		std::cout << "Event at " << startTime << " Succesfully scheduled!" << std::endl;
	}
	else {
		std::cout << "Event at " << startTime << " time slot is reserved!" << std::endl;
	}
	return insertResult.second;
}

void displayScheduledEvents(const std::set<int>& events) {
	std::cout << "Scheduled Events:" << std::endl;

	if (events.empty()) {
		std::cout << "No events scheduled!" << std::endl;
		return;
	}

	for (int time : events) {
		std::cout << time << " minutes." << std::endl;
	}

	std::cout << "---------------------" << std::endl;
}

int main() {
	std::set<int> myCalendar;
	std::cout << "Attempting to schedule events for the first time" << std::endl;
	for (int time : {900, 1030, 1300, 1400}) {
		scheduleEvent(myCalendar, time);
	}
	displayScheduledEvents(myCalendar);

	std::cout << "Attempting to schedule a conflicting event" << std::endl;
	scheduleEvent(myCalendar, 1030);
	displayScheduledEvents(myCalendar);

	scheduleEvent(myCalendar, 1200);
	displayScheduledEvents(myCalendar);

	std::cout << "Attempting to schedule a batch of events" << std::endl;
	std::vector<int> newEventTimes = { 800, 1400, 1600, 900, 1800 };
	for (int time : newEventTimes) {
		scheduleEvent(myCalendar, time);
	}
	displayScheduledEvents(myCalendar);
}