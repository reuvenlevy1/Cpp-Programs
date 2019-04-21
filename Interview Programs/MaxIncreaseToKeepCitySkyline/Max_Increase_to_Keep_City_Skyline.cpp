/**
* 807.	Max Increase to Keep City Skyline
* https://leetcode.com/problems/max-increase-to-keep-city-skyline/
* 
* @author Reuven
*/

#include <iostream>
#include <vector>

class Solution {
	std::vector<std::vector<int>> newGrid;
	int increasedSum;
public:
	int maxIncreaseKeepingSkyline(std::vector< std::vector<int> >& grid) {		//Accepts reference to multidimensional vector
		newGrid = grid;											//copy grid vector
		
		//Displays vector contents
		std::cout << "original grid: \n";
		for (size_t i = 0; i < newGrid.size(); i++) {			//Using int instead of size_t produces '<': signed / unsigned mismatch warnings (C4018)
			for (size_t j = 0; j < newGrid[i].size(); j++)
				std::cout << newGrid[i][j] << " ";
			std::cout << "\n";
		}
		std::cout << "\n";
		_findMaxValues();
		return increasedSum;
	}

private:
	
	/* locates the maximum row and column values for given grid */
	void _findMaxValues() {
		size_t i, j, k;
		int rowMaxValue, columnMaxValue;						//holds a single max value
		std::vector<int> maxRow, maxColumn;						//holds the single max value of each row & column respectively
		
		//Compares all rows & columns for max value
		for (i = 0; i < newGrid.size(); ++i) {
			rowMaxValue = newGrid[i][0];						//starting number of every row
			columnMaxValue = newGrid[0][i];						//starting number of every column

			for (j = 0; j < newGrid[0].size(); ++j) {
				if (rowMaxValue < newGrid[i][j])
					rowMaxValue = newGrid[i][j];
				if (columnMaxValue < newGrid[j][i])
					columnMaxValue = newGrid[j][i];
			}
			maxRow.push_back(rowMaxValue);						//Store max number in row
			maxColumn.push_back(columnMaxValue);				//Store max number in column
		}
		
		//Displays vector of max row values
		std::cout << "row values: ";
		for (k = 0; k < std::size(maxRow); ++k) {
			std::cout << maxRow[k] << " ";
		}

		//Displays vector of max column values
		std::cout << "\ncolumn values: ";
		for (k = 0; k < std::size(maxColumn); ++k) {
			std::cout << maxColumn[k] << " ";
		}
		std::cout << "\n\n";
		_increaseBuildingHeight(maxRow, maxColumn);
	}

	/* increases the size of newGrid by the minimum between the row and column at the given coordinate */
	void _increaseBuildingHeight(std::vector<int> maxRow, std::vector<int> maxColumn) {
		size_t i, j;
		int min;
		
		//Finds minimum number at given coordinate between maxRow and maxColumn i.e. min(maxRow[0], maxColumn[1])
		for (i = 0; i < std::size(maxRow); ++i) {
			for (j = 0; j < std::size(maxColumn); ++j) {
				min = maxRow[i];
				
				if (maxRow[i] < maxColumn[j])
					min = maxRow[i];
				else
					min = maxColumn[j];
				
				if (newGrid[i][j] < min) {
					increasedSum += (min - newGrid[i][j]);
					newGrid[i][j] = min;
				}
			}
		}
		
		//Displays new vector contents
		std::cout << "new grid: \n";
		for (i = 0; i < maxRow.size(); ++i) {
			for (j = 0; j < maxColumn.size(); ++j)
				std::cout << newGrid[i][j] << " ";
			std::cout << "\n";
		}
		std::cout << "\n";
	}
};


int main() {
	int sum;
	Solution s;

	std::vector<std::vector<int> > grid{ {3, 0, 8, 4},
										 {2, 4, 5, 7},
										 {9, 2, 6, 3},
										 {0, 3, 1, 0} };
	sum = s.maxIncreaseKeepingSkyline(grid);
	s.maxIncreaseKeepingSkyline(grid);
	std::cout << "Output: " << sum << "\n";
}
