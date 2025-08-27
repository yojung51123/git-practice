#include <iostream>
#include <vector>
#include <string>

// PotionRecipe 클래스: 재료 목록을 vector<string>으로 변경
class PotionRecipe {
public:
    std::string potionName;
    std::vector<std::string> ingredients; // 단일 재료에서 재료 '목록'으로 변경

    // 생성자: 재료 목록을 받아 초기화하도록 수정
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
        : potionName(name), ingredients(ingredients) {
    }
};

// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes; // 포션레시피를 타입으로 받고있는 벡터 , 변수이름 recipes[]

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
        recipes.push_back(PotionRecipe(name, ingredients)); // 포션이름 , 레시피 추가 
        std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
    }

    void searchRecipeByName(std::string name) const // 포션 검색
    {
        if (recipes.empty()) { // recipes가 비어있다면 아래문구 출력
            std::cout << "아직 등록된 포션이 없습니다." << std::endl;
            return;
        }
       
        std::cout << "\n--- [ 포션 검색창 ] ---" << std::endl; // 포션네임 1 재료목록 전부 -> 포션 2
        for (size_t i = 0; i < recipes.size(); ++i)
        {
            
            if(recipes[i].potionName == name)
            {
                 std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl; // recipes 배열에 저장된 포션네임을 불러온다
                 std::cout << "  > 필요 재료: "; 

            // 재료 목록을 순회하며 출력
                 for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)// recipes배열에 있는 재료의 목록이 j보다 크다면 반복 실행
                 {
                    std::cout << recipes[i].ingredients[j];
                // 마지막 재료가 아니면 쉼표로 구분
                    if (j < recipes[i].ingredients.size() - 1)
                    {
                    std::cout << ", ";
                    }
                 }
                    std::cout << std::endl;
            }
            else// 조건에 맞지않는다면
            {
                std::cout << "입력한 포션이 없습니다." << std::endl;
            }
        }

        std::cout << "---------------------------\n"; // 끝나면 -------- 출력

    }

    void searchRecipeByIngredient(/*std::vector<std::string>& ingredients*/std::string ingreients) const // 포션 검색
    {
        if (recipes.empty()) { // recipes가 비어있다면 아래문구 출력
            std::cout << "아직 등록된 포션이 없습니다." << std::endl;
            return;
        }
       
        std::cout << "\n--- [ 포션 검색창 ] ---" << std::endl; // 포션네임 1 재료목록 전부 -> 포션 2
        for (size_t i = 0; i < recipes.size(); ++i)
        {      
            // 재료 목록을 순회하며 출력
             for (size_t j = 0; j < recipes[i].ingredients.size(); ++j)// recipes배열에 있는 재료의 목록이 j보다 크다면 반복 실행
             {
                if (recipes[i].ingredients[j] == ingreients)
                {
                    std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl; // recipes 배열에 저장된 포션네임을 불러온다
                    std::cout << "  > 필요 재료: ";
                   // std::cout << recipes[i].ingredients[j];
                    // 마지막 재료가 아니면 쉼표로 구분
                    for (size_t k = 0; k < recipes[i].ingredients.size(); ++k) {
                        std::cout << recipes[i].ingredients[k];

                       if (k < recipes[i].ingredients.size() - 1) std::cout << ", ";
      
                    }
                }
                  
             }
             std::cout << std::endl;
             break;
        }

        std::cout << "---------------------------\n"; // 끝나면 -------- 출력

    }

   

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const {
        if (recipes.empty()) { // recipes가 비어있다면 아래문구 출력
            std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
            return; 

        }

        std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl; // 포션네임 1 재료목록 전부 -> 포션 2
        for (size_t i = 0; i < recipes.size(); ++i) {
            std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl; // recipes 배열에 저장된 포션네임을 불러온다
            std::cout << "  > 필요 재료: "; // 재료출력하는부분 비어있음

            // 재료 목록을 순회하며 출력
            for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {// recipes배열에 있는 재료의 목록이 j보다 크다면 반복 실행
                std::cout << recipes[i].ingredients[j];
                // 마지막 재료가 아니면 쉼표로 구분
                if (j < recipes[i].ingredients.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------------\n"; // 끝나면 -------- 출력
    }
};


int main() {
    AlchemyWorkshop myWorkshop; // 클래스 AlchemyWorkshop에 있는걸 사용하기위해 쓰는 변수

    while (true) { // 출력 메뉴
        std::cout << "* 연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 물약 이름 검색" << std::endl;
        std::cout << "4. 재료 검색" << std::endl;
        std::cout << "5. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice; // 받은 입력값 저장

        if (std::cin.fail()) { // 입력이 숫자가 아닐시
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear(); // 에러상태를 초기화 시킨다
            std::cin.ignore(10000, '\n');// 최대 10000글자 무시, 개행문자 나올때 까지 무시 기본형 (n, delim)
            continue; // 반복문에서 사용 다음반복으로 건너뜀
        }

        if (choice == 1) {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');// 최대 10000글자 무시, 개행문자 나올때 까지 무시 기본형 (n, delim)
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient); // 엔터전까지 띄워쓰기 포함해서 입력 ingredient에 저장

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient); // 스트링타입 ingredients_input 벡터 맨뒤에 ingredient의 값으로 추가한다
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) { // ingredients_input가 하나이상 있을때 ( 재료 )
                myWorkshop.addRecipe(name, ingredients_input);// addRecipe함수에 포션이름 , 입력받은 ingredients_input 벡터값을 인자로 넘겨준다
            }
            else {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl; //(ingredients_input) 값이 비었다면 메세지 출력
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes(); // 레시피출력 함수 호출

        }
        else if (choice == 3) // 물약 검색 기능
        {
            std::string name;
            std::cout << "물약의 이름을 입력하세요 :" << std::endl; // 이름 입력 요청 
            std::cin.ignore(10000, '\n');// 최대 10000글자 무시, 개행문자 나올때 까지 무시 기본형 (n, delim)
            std::getline(std::cin, name);
            myWorkshop.searchRecipeByName(name); // 이름으로 검색
        }
          
        else if (choice == 4) // 재료로 검색하기
        {
            std::string input;
            std::cout << "필요한 재료를 입력하세요." << std::endl;
            std::cin >> input;
            myWorkshop.searchRecipeByIngredient(input);
        }
           
        else if (choice == 5) {
            std::cout << "공방 문을 닫습니다..." << std::endl; // 끝내기
            break;
        }
        else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl; // 다시 입력문구
        }
    }

    return 0;
}