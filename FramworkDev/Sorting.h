
enum SORT_ORDER
{
	ascending,
	descending,
};

class Sorting
{
	int* a;

	//Count of the array
	int count;

	//Allocated size
	int AllocSize;

	public:
	
	Sorting(int size);
	
	//Add data to the array
	void AddData(int data);

	//Insertion Sort implementation
	void InsertionSort(SORT_ORDER type);
	
	//Selection Sort implementation
	void SelectionSort(SORT_ORDER type);

	//Bubble Sort implementation
	void BubbleSort(SORT_ORDER type);
	
	//Print the data
	void PrintData();
};