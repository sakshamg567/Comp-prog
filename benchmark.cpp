#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <limits>

using namespace std;
using namespace std::chrono;

/**
 * @brief A simple benchmarking program that measures execution time statistics
 * 
 * This program runs a specified command multiple times and measures its execution time,
 * calculating statistics like best, worst and average running times.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line arguments:
 *             argv[0]: Program name
 *             argv[1]: Command to benchmark
 * 
 * @return int Returns 0 on successful execution, 1 if insufficient arguments
 * 
 * Usage example: ./benchmark "myprogram.exe"
 * 
 * The program performs the following:
 * - Runs the specified command 1000 times
 * - Measures execution time for each run using high resolution clock
 * - Tracks best, worst and average execution times in milliseconds
 * - Warns if program exits with non-zero status
 * - Displays final statistics
 */
int main(int argc, char *argv[])
{
   if (argc < 2)
   {
      cerr << "Usage: " << argv[0] << " <program_to_benchmark>\n";
      return 1;
   }

   string command = argv[1]; // Program to run
   const int runs = 1000;
   vector<double> times;

   double best_time = numeric_limits<double>::max();
   double worst_time = 0;
   double total_time = 0;

   for (int i = 0; i < runs; ++i)
   {
      auto start = high_resolution_clock::now();
      int exit_code = system(command.c_str());
      auto end = high_resolution_clock::now();

      if (exit_code != 0)
      {
         cerr << "Warning: Program exited with non-zero status.\n";
      }

      double duration = duration_cast<microseconds>(end - start).count() / 1000.0; // Convert to ms
      times.push_back(duration);

      best_time = min(best_time, duration);
      worst_time = max(worst_time, duration);
      total_time += duration;
   }

   double avg_time = total_time / runs;

   cout << "Benchmark results for: " << command << "\n";
   cout << "Best Time: " << best_time << " ms\n";
   cout << "Worst Time: " << worst_time << " ms\n";
   cout << "Avg Time: " << avg_time << " ms\n";

   return 0;
}
