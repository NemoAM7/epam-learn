#include<iostream>
using namespace std;

class Playable {
public:
	virtual void play() = 0;
	virtual void pause() = 0;
};

class Recordable {
public:
	virtual void record() = 0;
	virtual void stop() = 0;
};

class MediaPlayer : public Playable, public Recordable {
private:
	bool recording;
	bool playing;

public:
	MediaPlayer() : recording(false), playing(false) {}

	void play() {
		if (playing) {
			cout << "MediaPlayer: Already playing!" << endl;
			return;
		}
		cout << "MediaPlayer: Now playing!" << endl;
		playing = true;
		
	}
	void pause() {
		if (!playing) {
			cout << "MediaPlayer: Already paused!" << endl;
			return;
		}
		cout << "MediaPlayer: Now paused!" << endl;
		playing = false;
	}

	void record() {
		if (recording) {
			cout << "MediaPlayer: Already recording!" << endl;
			return;
		}
		cout << "MediaPlayer: Now recording!" << endl;
		recording = true;
	}

	void stop() {
		if (!recording) {
			cout << "MediaPlayer: Already stopped!" << endl;
			return;
		}
		cout << "MediaPlayer: Now stopped!" << endl;
		recording = false;
	}
};

int main() {
	MediaPlayer mp;
	Playable* p = &mp; p->play(); p->pause();
	Recordable* r = &mp; r->record(); r->stop();
}