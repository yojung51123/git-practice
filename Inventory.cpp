#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Inventory
{
private:
    T* pItems_;
    int capacity_; // �κ��丮�� �ִ�� ���� �� �� �ִ� ������ ũ��
    int size_;     // ���� �κ��丮�� ����� �������� ���� ����

public:
    Inventory(int capacity_ = 10)
        : capacity_(capacity_ > 0 ? capacity_ : 1),
        size_(0),
        pItems_(nullptr)
    {
        pItems_ = new T[capacity_];
    };

    virtual ~Inventory()
    {
        delete[] pItems_;
        pItems_ = nullptr;
    };

    void printItemMenu()
    {
        cout << "===================" << endl;
        cout << " 1. �� " << endl;
        cout << " 2. ���� " << endl;
        cout << " 3. ������" << endl;
        cout << "===================" << endl;
    }

    void printMenu()
    {
        cout << "======================================" << endl;
        cout << " 1. ������ ���� " << endl;
        cout << " 2. ������ ������ " << endl;
        cout << " 3. ������ ���� Ȯ��" << endl;
        cout << " 4. �κ��丮 �ִ� ���� �뷮 Ȯ��" << endl;
        cout << " 5. ��� ������ ���� Ȯ��" << endl;
        cout << " 6. �κ��丮 â �ݱ�" << endl;
        cout << "======================================" << endl;
    }

    void AddItem(const T& item)
    {
        if (size_ < capacity_)
        {
            pItems_[size_++] = item;
            cout << "* ���� ���� ������ " << capacity_ - size_ << " ĭ �Դϴ�." << endl;
        }
        else
        {
            cout << "�κ��丮�� ���� á���ϴ�!" << endl;
        }
    }

    void RemoveLastItem()
    {
        if (size_ > 0)
        {
            cout << "* ������ �������� ���Ƚ��ϴ�." << endl;
            size_--;
        }
        else
        {
            cout << "�κ��丮�� ������ϴ�." << endl;
        }
    }

    void printAllItems() const
    {
        if (size_ > 0)
        {
            for (int i = 0; i < size_; i++)
            {
                pItems_[i].PrintInfo();
            }
        
        }
        else
        {
            cout << "(�������)" << endl;
        }
    }

    int GetSize() const 
    {
        return size_; 
    }
    int Getcapacity() const 
    {
        return capacity_; 
  
    }

};

struct Item //����ü - ���ξ�������� �����
{
    string name_;
    int price_;

    void PrintInfo() const
    {
        cout << "[������ �̸�: " << name_ << ", ����: " << price_ << "G]" << endl;
    }
};


int main()
{
    int choice = 0;
    Inventory<Item> inv(10);
    int Itemchoice;

    cout << "�κ��丮�� �������ϴ�. ������ �Ͻðڽ��ϱ�?" << endl;

    while (choice != 6)
    {
        inv.printMenu();
        cout << "* ��ȣ�� ���� ���ּ���." << endl;
        cin >> choice;

        if (choice == 1)
        {
            inv.printItemMenu();
            cout << "* �������� ���� ���ּ���." << endl;
            cin >> Itemchoice;

            if (Itemchoice == 1)
            {
                cout << "* ���� ȹ�� �߽��ϴ�." << endl;
                inv.AddItem({"��", 500});
            }
            else if (Itemchoice == 2)
            {
                cout << "* ������ ȹ�� �߽��ϴ�." << endl;
                inv.AddItem({"����", 200});
            }
            else if (Itemchoice == 3)
            {
                cout << "* �������� ȹ�� �߽��ϴ�." << endl;
                inv.AddItem({ "������", 100 });
            }
            else
            {
                cout << "* ��ȣ�� �ٽ� �Է����ּ���" << endl;
            }
        }
        else if (choice == 2)
        {
            inv.RemoveLastItem();
        }
        else if (choice == 3)
        {
            cout << "* ���� ������ ������ " << inv.GetSize() << " �� �Դϴ�." << endl;
        }
        else if (choice == 4)
        {
            cout << "* �κ��丮 �ִ� ����뷮�� " << inv.Getcapacity() << " �Դϴ�." << endl;
        }
        else if (choice == 5)
        {
            cout << "* ��� ������ ������ Ȯ�� �մϴ�." << endl;
            inv.printAllItems();
        }
        else if (choice == 6)
        {
            cout << "* �κ��丮â�� �ݽ��ϴ�." << endl;
        }
        else
        {
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է� ���ּ���." << endl;
        }
    }
}
