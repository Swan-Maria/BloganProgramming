#include <iostream>
#include <string>
#include "Lesson 144 BinaryTree.h"

template <typename T>
void ShowValue(const T& value)
{
    std::cout << value << " ";
}

template <typename T>
void Show(const BinaryTree<T>& tree)
{
    std::cout << "Tree elements: ";
    tree.DoForAllElements(ShowValue<T>);
    std::cout << std::endl;
}

template <typename T>
class Sum
{
public:
	static T sum;
	static void Add(const T& value)
	{
		sum += value;
	}
};

template <typename T>
T Sum<T>::sum = 0;

int main()
{
    // Constructors:
    {
        std::cout << "--- Constructors --- \\n";

        BinaryTree<int> tree1;                // default constructor
        Show(tree1);

        BinaryTree<int> tree2{ 10, 1, 9, 2, 8, 3 }; // std::initializer_list constructor
        Show(tree2);

        BinaryTree<int> tree3(tree2);         // copy constructor
        Show(tree3);

        BinaryTree<int> tree4(std::move(tree3)); // move constructor
        Show(tree4);
        Show(tree3);
    }

    // Operators = 
    {
        std::cout << "\n --- Operators = --- \n";
        BinaryTree<int> tree1{ 1, 2, 3, 4, 5 };
        BinaryTree<int> tree2{ 10, 20, 30 };

        Show(tree1);
        Show(tree2);

        tree2 = tree1; // copy assignment operator
        Show(tree1);
        Show(tree2);

        // Operators = 
        {
            std::cout << "\n --- Operators = --- \n";
            BinaryTree<int> tree1{ 1, 2, 3, 4, 5 };
            BinaryTree<int> tree2{ 10, 20, 30 };

            Show(tree1);
            Show(tree2);

            tree2 = tree1; // copy assignment operator
            Show(tree1);
            Show(tree2);

            BinaryTree<int> tree3{ 11, 22, 33, 44, 55 };
            BinaryTree<int> tree4{ 100, 200, 300 };

            Show(tree3);
            Show(tree4);

            tree4 = std::move(tree3); // move assignment operator
            Show(tree3);
            Show(tree4);
        }
    }

    // Methods:
    {
        std::cout << "\n --- Methods --- \n";

        BinaryTree<double> tree1{ 1.1, 2.2, 3.3, 4.4, 5.5 };

        if (!tree1.IsEmpty()) // Method #1
        {
            std::cout << "Tree #1 isn't empty.\n";
        }

        std::cout << "Size of Tree #1 = " << tree1.Size() << std::endl; // Method #2

        tree1.Clear(); // Method #3

        if (tree1.IsEmpty())
        {
            std::cout << "Tree #1 is empty now.\n";
        }

        tree1.Insert(10.5); // Method #4
        tree1.Insert(2.8);
        tree1.Insert(1.2);
        tree1.Insert(3.6);
        tree1.Insert(7.8);

        std::cout << "Tree #1 elements: ";
        tree1.DoForAllElements(ShowValue<double>); // Method #5

        const double* foundValue = tree1.Find(2.8); // Method #6
        if (foundValue != nullptr)
        {
            std::cout << "\nTree #1 has " << *foundValue << std::endl;
        }

        tree1.Delete(32.1); // Method #7
        tree1.Delete(2.8);

        std::cout << "Tree #1 elements: ";
        tree1.DoForAllElements(ShowValue<double>);

        // Задача: знайти суму всіх елементів (через ітератор)
        //By class
        {
            tree1.DoForAllElements(Sum<double>::Add); 
            std::cout << "\nSum = " << Sum<double>::sum << std::endl;
        }
        // By lambda
        {
            double sum = 0.0;
            tree1.DoForAllElements([&sum](const double& value) { sum += value; });
            std::cout << "Sum = " << sum << std::endl;
        }
        // By lambda
        {
            double sum = 0.0;
            auto function = [&sum](const double& value) { sum += value; };
            tree1.DoForAllElements(function); // By lambda
        }
    }

    return 0;
}
