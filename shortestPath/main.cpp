#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

/* Data Structures for solution */
struct Point
{
    std::string pointName;
    int x;
    int y;
    Point(std::string name, int m, int n) : pointName{name},x{m}, y{n} {}
};

std::vector<Point> coordinates;
std::list<std::string> shortestPathData;
int totalPoints;

/* Functions for solution */
int square(int input)
{
    return input*input;
}

int calculateDistance(Point& p1, Point& p2)
{
    return (square(p1.x - p2.x) + square(p1.y - p2.y));
}

bool getInputCoordinates()
{
    bool retVal = false;
    std::ifstream iFile("D:\\src\\algorithms\\shortestPath\\input.txt");
    std::string line, token;
    
    if(iFile.is_open())
    {
        Point p("",0,0);
        while(std::getline(iFile, line, ','))
        {
            /* Extract the comma separated values and store them into a point object */
            std::stringstream ss(line);
            int i = 0;
            while(std::getline(ss, token, ',') && (i<3))
            {
                if(i == 0)
                {
                    p.pointName = token;
                }
                else if(i == 1)
                {
                    p.x = std::stoi(token);
                }
                else if(i == 2)
                {
                    p.y = std::stoi(token);
                }

                i++;
            }
            coordinates.push_back(p);
        }
        totalPoints = coordinates.size();
        std::cout<<"Number of coordinates received : "<<totalPoints<<"\n";
        retVal = true;
    }
    else
    {
        std::cerr<<"Unable to open file \n";
    }

    return retVal;
}

void getShortestRoute()
{
    std::string startingPoint, nextPoint;
    while(coordinates.empty())
    {
        startingPoint = coordinates[totalPoints-1].pointName;
        nextPoint = getNextNearestPoint();
    }
}


int main()
{
    /* Get the input points coordinates */
    if(!getInputCoordinates())
    {
        std::cout <<"Failed to get input coordinates \n";
    }

    /* 
    1. Choose first coordinate as begining point.
    2. Calculate the next nearest point : calculate distance of all remaining points.
    3. The nearest point is the next point in destination.
     */
    getShortestRoute();


    /* Traverse*/

    std::cin.get();
    return 0;
}