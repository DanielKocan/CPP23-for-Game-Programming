#include <fstream>
#include <iostream>

struct highscore
{
	char name[4];
	uint32_t score; // guarantide to be 32 bits on every platform! (with int it can be different)
};

int main()
{
	// Write ASCII files.
	{
		std::ofstream highscores("highscores.txt");
		if (!highscores)
		{
			// an error stream
			std::cerr << "ERROR: could not open files for writing." << std::endl;
			return 1;
		}

		highscores << "DAN " << 2014 << std::endl;
		highscores << "TOM " << 2012 << std::endl;
		highscores << "LUC " << 2009 << std::endl;
		highscores << "SUZ " << 1978 << std::endl;

		if (highscores.bad())
		{
			std::cerr << "ERROR:  an error occured while writing to the file" << std::endl;
			return 1;
		}

		highscores.close();
		// RAII RAII - resource acquisition is initialization. The core idea : Tie a resource's lifetime to an object's lifetime.Acquire in the constructor, release in the destructor.When the object goes out of scope, cleanup happens** automatically.
	}

	{
		std::ofstream highscores("highscores.txt", std::ios::app); // append data to the file! dont delete inside of it.
		if (!highscores)
		{
			// an error stream
			std::cerr << "faile to open file." << std::endl;
			return 1;
		}

		highscores << "JER " << 1977 << std::endl;

		if (highscores.bad())
		{
			std::cerr << "ERROR:  an error occured while writing to the file" << std::endl;
			return 1;
		}

		highscores.close();
	}

	{
		std::ifstream highscores("highscores.txt");
		if (!highscores)
		{
			// an error stream
			std::cerr << "ERROR: Failed to open file." << std::endl;
			return 1;
		}

		char name[4]; // hiddne character null terminator (says that this is the end of the stream we need one byte for it)
		int score;
		while (highscores >> name >> score)
		{
			std::cout << name << " " << score << std::endl;
		}

		if (highscores.bad())
		{
			std::cerr << "ERROR: Failed to open file" << std::endl;
			return 1;
		}

		highscores.close();
	}

	// Writing binary files
	{
		std::ofstream highscores("highscores.bin", std::ios::binary);
		if(!highscores)
		{
			std::cerr << "ERROR: Failed to open file" << std::endl;
			return 1;
		}

		highscore scores[] = {
			{"DAN", 2014},
			{"TOM", 2012},
			{"LUC", 2009},
			{"SUZ", 1978},
			{"JER", 1977},
		};
		auto numScores = std::size(scores);

		highscores.write(reinterpret_cast<const char*>(&numScores), sizeof(numScores));
		highscores.write(reinterpret_cast<const char*>(scores), numScores * sizeof(highscore));

		if (highscores.bad())
		{
			std::cerr << "ERROR: Failed to open file" << std::endl;
			return 1;
		}

		highscores.close();
	}

	std::cout << std::endl;

	//Reading from a binary files
	{
		std::ifstream highscores("highscores.bin", std::ios::binary);
		if (!highscores)
		{
			std::cerr << "ERROR: Failed to open file" << std::endl;
			return 1;
		}

		size_t numEntries;
		// On binary files we need to use read! not <<
		highscores.read(reinterpret_cast<char*>(&numEntries), sizeof(numEntries));

		//allocarte new memory from the heap
		highscore* scores = new highscore[numEntries];

		highscores.read(reinterpret_cast<char*>(scores), numEntries * sizeof(highscore));

		if (highscores.bad())
		{
			std::cerr << "ERROR: Failed to open file" << std::endl;
			return 1;
		}

		for (int i = 0; i < numEntries; ++i)
		{
			std::cout << scores[i].name << " " << scores[i].score << std::endl;
		}

		delete[] scores;
		highscores.close();
	}

	return 0;
}