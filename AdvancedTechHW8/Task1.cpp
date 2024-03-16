#include <iostream>
#include "lib.h"
#include <string>
#include <vector>
#include <map>
#include <random>


using namespace std;


enum Condition {
	ON_PAUSE,
	PLAYING,
	SILENCE
};


struct Track {

	public:
		string name;
		tm date;
		int duration;


};


class AudioPlayer {

	private:

		vector<Track> tracks;

		map<string, Track> tracksMap;

		Track track_;

		Condition condition;

		AudioPlayer(): condition(Condition::SILENCE) {
		
			// some logic of tracks loading from file or etc... 

		}


	public:

		void play() {

			string name;
		
			cout << "Please, choose the song you would like to listen to..." << endl;

			cin >> name;

			if (tracksMap.count(name)) {
			
				if (condition == Condition::SILENCE) {
				
					track_ = tracksMap[name];

					condition = Condition::PLAYING;
				
					cout <<"PLAYING: " << track_.name << track_.duration << track_.date.tm_year
						<< track_.date.tm_mon << track_.date.tm_mday << endl;
				}

			}
			else {
			
				cout << "Sorry, but there is no such track in library..." << endl;

			}
		}

		void pause() {
			
			if (condition == Condition::PLAYING) {

				condition = Condition::ON_PAUSE;
			
				cout << "ON PAUSE!" << endl;

			}
			else if (condition == Condition::ON_PAUSE) {

				condition = Condition::PLAYING;
			
				cout << "Continue PLAYING...";
			}
		}

		void next() {
		
			condition = Condition::PLAYING;

			track_ = tracks[rand() % tracks.size()];

			cout << "PLAYING NEXT RANDOM SONG: " << track_.name << track_.duration << track_.date.tm_year
				<< track_.date.tm_mon << track_.date.tm_mday << endl;
		}

		void stop() {
		
			if (condition != Condition::SILENCE) {
			
				condition = Condition::SILENCE;

				cout << "SONG HAS BEEN STOPPED..." << endl;
			}

		}

		void exit() {
		
			cout << "exitting..." << endl;

		}

};


void task1() {

	// ...

}
