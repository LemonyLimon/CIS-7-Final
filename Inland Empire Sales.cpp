// Melanie Caines
// November 26th, 2023
// CIS-7 Final
// Case 1: Inland Empire Solar Sales Travel
// This program is created to provide a output of how many miles a solar sales travel person can expect to drive if 
// there are makding a roundtrip commute in-between the cities of Riverside, Hemet, Perris, and Moreno Valley.

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Data structure to store the cities and total miles in a designated path
struct pathWays 
{
    string city1, city2, city3, city4, destination;
    int range;
};

// Data structure to store graph, edges, and weight
struct Edge 
{
    string src, dest;
    int weight;
};

// Comparing the first column of the vector in the the second row to the fourth row
bool compareInterval(string T1, string T2)
{
    return (T1 < T2);
}

// Print all possible paths
void printPossiblePaths(vector<pathWays>& vectorPaths, int size)
{
    for (int i = 0; i < vectorPaths.size(); i++)
    {
        cout << vectorPaths[i].city1 << " -> " << vectorPaths[i].city2 << " -> " << vectorPaths[i].city3 << " -> " <<
            vectorPaths[i].city4 << " -> " << vectorPaths[i].destination << endl;
        cout << "Route " << i + 1 << ": " << vectorPaths[i].range << " Miles" << "\n" << endl;
    }
}

// Print the shortest path
void printshortestPath(vector<pathWays>& vectorPaths, int size)
{
    // Check if there are addtional short pathways
    int min; // Index of the minimum element
    for (int i = 1; i < size; i++) 
    {
        if (vectorPaths[0].range == vectorPaths[i].range)
            min = i;
    }

    // Print the shortest path
    cout << "\nThe shortest path is: \n";
    cout << vectorPaths[0].city1 << " -> " << vectorPaths[0].city2 << " -> " << vectorPaths[0].city3 << " -> " <<
        vectorPaths[0].city4 << " -> " << vectorPaths[0].destination << "\nThe distance is " <<
        vectorPaths[0].range << endl;
    cout << "Or\n";
    cout << vectorPaths[min].city1 << " -> " << vectorPaths[min].city2 << " -> " << vectorPaths[min].city3 << " -> " <<
        vectorPaths[min].city4 << " -> " << vectorPaths[min].destination << "\nThe distance is " <<
        vectorPaths[min].range << "\n" << endl;
}

// Print Lowest_cost path
void printlowest_Costpath(vector<pathWays>& vectorPaths, int size)
{
    // Check if there are addtional shortest paths
    int min; //index of the minimum element
    for (int i = 1; i < size; i++) 
     {
        if (vectorPaths[0].range == vectorPaths[i].range)
            min = i;
    }

    cout << "\nThe Lowest_Cost path is: \n";
    cout << vectorPaths[0].city1 << " -> " << vectorPaths[0].city2 << " -> " << vectorPaths[0].city3 << " -> " <<
        vectorPaths[0].city4 << " -> " << vectorPaths[0].destination << "\nThe distance is " <<
        vectorPaths[0].range << endl;
    cout << "Or\n";
    cout << vectorPaths[min].city1 << " -> " << vectorPaths[min].city2 << " -> " << vectorPaths[min].city3 << " -> " <<
        vectorPaths[min].city4 << " -> " << vectorPaths[min].destination << "\nThe distance is " <<
        vectorPaths[min].range << "\n" << endl;
}

// Print the longest path
void printlongestPath(vector<pathWays>& vectorPaths, int size)
{
    int k = size - 1;
    // Check if there are addtional longest paths
    int max; // Index of the maximum element
    for (int i = 0; i < k; i++) 
    {
        if (vectorPaths[k].range == vectorPaths[i].range)
            max = i;
    }

    // Print the longest path
    cout << "\nThe Longest path is: \n";
    cout << vectorPaths[k].city1 << " -> " << vectorPaths[k].city2 << " -> " << vectorPaths[k].city3 << " -> " <<
        vectorPaths[k].city4 << " -> " << vectorPaths[k].destination << "\nThe distance is " <<
        vectorPaths[k].range << endl;
    cout << "Or\n";
    cout << vectorPaths[max].city1 << " -> " << vectorPaths[max].city2 << " -> " << vectorPaths[max].city3 << " -> " <<
        vectorPaths[max].city4 << " -> " << vectorPaths[max].destination << "\nThe distance is " <<
        vectorPaths[max].range << "\n" << endl;
}



int main()
{
    // Cities that will be visited
    vector<string> trips = { "Hemet", "Moreno Valley", "Perris" }; 

    Edge edges[] = 
    {
        {"Riverside", "Hemet", 33},
        {"Riverside", "Perris", 24},
        {"Riverside", "Moreno Valley", 16},
        {"Hemet", "Moreno Valley", 26},
        {"Hemet", "Perris", 30},
        {"Perris", "Moreno Valley", 18}
    };

    int n = trips.size(); // Number of vertices that will be visited excluding the start city and ending city
    int m = sizeof(edges) / sizeof(edges[0]); // Number of edges

    int j = 0; // Index 
    pathWays path; // Create structure
    vector<string> cityTrips; // Vector of passing cities
    vector<pathWays> vectorPaths; // Vector of structure

    // Sorting the string vector 
    sort(trips.begin(), trips.end(), compareInterval); 

    // Permute pathways and calcuate total miles in the path
    do {
        int distance = 0;             
        for (int i = 0; i < n; i++) {
            cityTrips.push_back(trips[i]); // Adding the visited cities in the vector        

        }

        // Initialize the first element of the structure
        path.city1 = "Riverside"; 
        path.destination = "Riverside";
        path.city2 = cityTrips[0];
        path.city3 = cityTrips[1];
        path.city4 = cityTrips[2];

        // Calculate the total miles in the path
        for (int k = 0; k < m; k++) {
            if (edges[k].src == "Riverside" && path.city2 == edges[k].dest) 
            {
                distance += edges[k].weight;
            }

            if ((path.city2 == edges[k].src && path.city3 == edges[k].dest)
                || (path.city3 == edges[k].src && path.city2 == edges[k].dest)) 
            {
                distance += edges[k].weight;
            }

            if ((path.city3 == edges[k].src && path.city4 == edges[k].dest)
                || (path.city4 == edges[k].src && path.city3 == edges[k].dest)) 
            {
                distance += edges[k].weight;
            }

            if (edges[k].src == "Riverside" && path.city4 == edges[k].dest) 
            {
                distance += edges[k].weight;
            }
        }

        path.range = distance;
        vectorPaths.push_back(path);
        cityTrips.clear();
        path = {};
        j++;
    } while (next_permutation(trips.begin(), trips.end()));

    // Sort the vector of structures and sort possible pathways
    sort(vectorPaths.begin(), vectorPaths.end(), [](pathWays path1, pathWays path2)
        {
        return path1.range < path2.range;
        }
    );

    // Display user choice and input
    while (true) 
    {
        int choice; 
        cout << "Hello and welcome to the Inland Empire Market Route Overview!\n";
        cout << "From this screen you will be able to review routing for your planned visits.\n\n";
        cout << "Please make a selection:" << endl;
        cout << "1. Path Options: " << endl;
        cout << "2. Shortest Path: " << endl;
        cout << "3. Lowest Cost Path: " << endl;
        cout << "4. Longest Path: " << endl;
        cout << "5. Quit" << endl;
        cin >> choice;

        if (choice == 1)
            printPossiblePaths(vectorPaths, j);

        else if (choice == 2)
            printshortestPath(vectorPaths, j);

        else if (choice == 3)
            printlowest_Costpath(vectorPaths, j);

        else if (choice == 4)
            printlongestPath(vectorPaths, j);

        else if (choice == 5)
            cout << "Thank you for using this program. We hope to see you again soon."
            " Goodbye!\n", exit(0);

        else 
        {
            cout << "Please make another selection using options 1-5." << endl;
            cin >> choice;
        }
    }
    return 0;
}