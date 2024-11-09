#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int main()
{
    auto start = high_resolution_clock::now();

    int n;
    cout << "How many unique random numbers do you want in your txt file?" << endl;
    cin >> n;
    if (n > 100000)
    {
        cerr << "Error: Requested more than available range (1 to 100000)." << endl;
        return 1;
    }

    ofstream outFile("outFile.txt"), sorted("Sorted.txt");
    if (!outFile || !sorted)
    {
        cerr << "Error creating file." << endl;
        return 1;
    }

    vector<int> numbers(100000);
    iota(numbers.begin(), numbers.end(), 1);
    shuffle(numbers.begin(), numbers.end(), default_random_engine(random_device{}()));

    for (int i = 0; i < n; i++)
        outFile << numbers[i] << endl;
    outFile.close();

    ifstream inFile("outFile.txt");
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        inFile >> arr[i];
    inFile.close();

    sort(arr.begin(), arr.end());
    for (int x : arr)
        sorted << x << "\t";
    sorted.close();

    auto duration = duration_cast<seconds>(high_resolution_clock::now() - start);
    cout << "Sorted.txt created with execution time: " << duration.count() << " seconds" << endl;

    return 0;
}
