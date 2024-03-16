#include <iostream>
#include "lib.h"
#include <string>
#include <vector>
#include <map>
#include <random>


using namespace std;

const int WIDTH = 80, HEIGHT = 50;


class Window {

	private:
		// coords of the top left window point:
		int wj, wi;

		// width and height of the window:
		int width, height;



	public:

		Window(): wj(15), wi(30), height(20), width(20) {
		
			// ...
		
		}

		void move(int dj, int di) {
		
			// validating:
			if (wj + dj >= 0 && wj + dj + height < HEIGHT && wi + di >= 0 && wi + di + width < WIDTH) {

				wj += dj;
				wi += di;

			}
			else cout << "Invalid vector of movement..." << endl;

		}

		void resize(int newHeight, int newWidth) {
		
			// validating:
			if (wj >= 0 && wj + newHeight < HEIGHT && wi >= 0 && wi + newWidth < WIDTH) {

				height = newHeight;
				width = newWidth;

			}
			else cout << "Invalid sizes..." << endl;
		
		}

		void display() {

			cout << "Window: " << endl;
		
			for (size_t j = 0; j < HEIGHT; j++)
			{
				for (size_t i = 0; i < WIDTH; i++)
				{
					if (j >= wj && j < wj + height && i >= wi && i < wi + width) cout << 1;

					else cout << 0;
				}

				cout << endl;
			}

			cout << endl;
		}


		void close() {
		
			cout << "closing app..." << endl;
		
		}

};


void task3() {

	Window window;

	window.display();

	window.move(10, 10);

	window.display();

	window.move(10, 10);

	window.display();

	window.resize(5, 5);

	window.display();

	window.resize(98, 98);

}

