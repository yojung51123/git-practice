#include <iostream>
#include <vector>
#include <string>

// PotionRecipe Ŭ����: ��� ����� vector<string>���� ����
class PotionRecipe {
public:
    std::string potionName;
    std::vector<std::string> ingredients; // ���� ��ῡ�� ��� '���'���� ����

    // ������: ��� ����� �޾� �ʱ�ȭ�ϵ��� ����
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
        : potionName(name), ingredients(ingredients) {
    }
};

// AlchemyWorkshop Ŭ����: ������ ����� ����
class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes; // ���Ƿ����Ǹ� Ÿ������ �ް��ִ� ���� , �����̸� recipes[]

public:
    // addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
        recipes.push_back(PotionRecipe(name, ingredients)); // �����̸� , ������ �߰� 
        std::cout << ">> ���ο� ������ '" << name << "'��(��) �߰��Ǿ����ϴ�." << std::endl;
    }

    void searchRecipeByName(std::string name) const // ���� �˻�
    {
        if (recipes.empty()) { // recipes�� ����ִٸ� �Ʒ����� ���
            std::cout << "���� ��ϵ� ������ �����ϴ�." << std::endl;
            return;
        }
       
        std::cout << "\n--- [ ���� �˻�â ] ---" << std::endl; // ���ǳ��� 1 ����� ���� -> ���� 2
        for (size_t i = 0; i < recipes.size(); ++i)
        {
            
            if(recipes[i].potionName == name)
            {
                 std::cout << "- ���� �̸�: " << recipes[i].potionName << std::endl; // recipes �迭�� ����� ���ǳ����� �ҷ��´�
                 std::cout << "  > �ʿ� ���: "; 

            // ��� ����� ��ȸ�ϸ� ���
                 for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)// recipes�迭�� �ִ� ����� ����� j���� ũ�ٸ� �ݺ� ����
                 {
                    std::cout << recipes[i].ingredients[j];
                // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
                    if (j < recipes[i].ingredients.size() - 1)
                    {
                    std::cout << ", ";
                    }
                 }
                    std::cout << std::endl;
            }
            else// ���ǿ� �����ʴ´ٸ�
            {
                std::cout << "�Է��� ������ �����ϴ�." << std::endl;
            }
        }

        std::cout << "---------------------------\n"; // ������ -------- ���

    }

    void searchRecipeByIngredient(/*std::vector<std::string>& ingredients*/std::string ingreients) const // ���� �˻�
    {
        if (recipes.empty()) { // recipes�� ����ִٸ� �Ʒ����� ���
            std::cout << "���� ��ϵ� ������ �����ϴ�." << std::endl;
            return;
        }
       
        std::cout << "\n--- [ ���� �˻�â ] ---" << std::endl; // ���ǳ��� 1 ����� ���� -> ���� 2
        for (size_t i = 0; i < recipes.size(); ++i)
        {      
            // ��� ����� ��ȸ�ϸ� ���
             for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)// recipes�迭�� �ִ� ����� ����� j���� ũ�ٸ� �ݺ� ����
             {
                if (recipes[i].ingredients[j] == ingreients)
                {
                    std::cout << "- ���� �̸�: " << recipes[i].potionName << std::endl; // recipes �迭�� ����� ���ǳ����� �ҷ��´�
                    std::cout << "  > �ʿ� ���: ";
                   // std::cout << recipes[i].ingredients[j];
                    // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
                    for (size_t k = 0; k < recipes[i].ingredients.size(); ++k) {
                        std::cout << recipes[i].ingredients[k];

                       if (k < recipes[i].ingredients.size() - 1) std::cout << ", ";
      
                    }
                }
                  
             }
             std::cout << std::endl;
             break;
        }

        std::cout << "---------------------------\n"; // ������ -------- ���

    }

   

    // ��� ������ ��� �޼���
    void displayAllRecipes() const {
        if (recipes.empty()) { // recipes�� ����ִٸ� �Ʒ����� ���
            std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
            return; 

        }

        std::cout << "\n--- [ ��ü ������ ��� ] ---" << std::endl; // ���ǳ��� 1 ����� ���� -> ���� 2
        for (size_t i = 0; i < recipes.size(); ++i) {
            std::cout << "- ���� �̸�: " << recipes[i].potionName << std::endl; // recipes �迭�� ����� ���ǳ����� �ҷ��´�
            std::cout << "  > �ʿ� ���: "; // �������ϴºκ� �������

            // ��� ����� ��ȸ�ϸ� ���
            for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {// recipes�迭�� �ִ� ����� ����� j���� ũ�ٸ� �ݺ� ����
                std::cout << recipes[i].ingredients[j];
                // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
                if (j < recipes[i].ingredients.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------------\n"; // ������ -------- ���
    }
};


int main() {
    AlchemyWorkshop myWorkshop; // Ŭ���� AlchemyWorkshop�� �ִ°� ����ϱ����� ���� ����

    while (true) { // ��� �޴�
        std::cout << "* ���ݼ� ���� ���� �ý���" << std::endl;
        std::cout << "1. ������ �߰�" << std::endl;
        std::cout << "2. ��� ������ ���" << std::endl;
        std::cout << "3. ���� �̸� �˻�" << std::endl;
        std::cout << "4. ��� �˻�" << std::endl;
        std::cout << "5. ����" << std::endl;
        std::cout << "����: ";

        int choice;
        std::cin >> choice; // ���� �Է°� ����

        if (std::cin.fail()) { // �Է��� ���ڰ� �ƴҽ�
            std::cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << std::endl;
            std::cin.clear(); // �������¸� �ʱ�ȭ ��Ų��
            std::cin.ignore(10000, '\n');// �ִ� 10000���� ����, ���๮�� ���ö� ���� ���� �⺻�� (n, delim)
            continue; // �ݺ������� ��� �����ݺ����� �ǳʶ�
        }

        if (choice == 1) {
            std::string name;
            std::cout << "���� �̸�: ";
            std::cin.ignore(10000, '\n');// �ִ� 10000���� ����, ���๮�� ���ö� ���� ���� �⺻�� (n, delim)
            std::getline(std::cin, name);

            // ���� ��Ḧ �Է¹ޱ� ���� ����
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "�ʿ��� ������ �Է��ϼ���. (�Է� �Ϸ� �� '��' �Է�)" << std::endl;

            while (true) {
                std::cout << "��� �Է�: ";
                std::getline(std::cin, ingredient); // ���������� ������� �����ؼ� �Է� ingredient�� ����

                // ����ڰ� '��'�� �Է��ϸ� ��� �Է� ����
                if (ingredient == "��") {
                    break;
                }
                ingredients_input.push_back(ingredient); // ��Ʈ��Ÿ�� ingredients_input ���� �ǵڿ� ingredient�� ������ �߰��Ѵ�
            }

            // �Է¹��� ��ᰡ �ϳ� �̻� ���� ���� ������ �߰�
            if (!ingredients_input.empty()) { // ingredients_input�� �ϳ��̻� ������ ( ��� )
                myWorkshop.addRecipe(name, ingredients_input);// addRecipe�Լ��� �����̸� , �Է¹��� ingredients_input ���Ͱ��� ���ڷ� �Ѱ��ش�
            }
            else {
                std::cout << ">> ��ᰡ �Էµ��� �ʾ� ������ �߰��� ����մϴ�." << std::endl; //(ingredients_input) ���� ����ٸ� �޼��� ���
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes(); // ��������� �Լ� ȣ��

        }
        else if (choice == 3) // ���� �˻� ���
        {
            std::string name;
            std::cout << "������ �̸��� �Է��ϼ��� :" << std::endl; // �̸� �Է� ��û 
            std::cin.ignore(10000, '\n');// �ִ� 10000���� ����, ���๮�� ���ö� ���� ���� �⺻�� (n, delim)
            std::getline(std::cin, name);
            myWorkshop.searchRecipeByName(name); // �̸����� �˻�
        }
          
        else if (choice == 4) // ���� �˻��ϱ�
        {
            std::string input;
            std::cout << "�ʿ��� ��Ḧ �Է��ϼ���." << std::endl;
            std::cin >> input;
            myWorkshop.searchRecipeByIngredient(input);
        }
           
        else if (choice == 5) {
            std::cout << "���� ���� �ݽ��ϴ�..." << std::endl; // ������
            break;
        }
        else {
            std::cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << std::endl; // �ٽ� �Է¹���
        }
    }

    return 0;
}