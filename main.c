#include <stdio.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;           // 상품 ID
    int stock;        // 입고 수량
    int sold;         // 판매 수량
    int remaining;    // 남은 재고
} Product;

int main() {
    int n, i;
    int totalStock = 0, totalSold = 0;
    float salesRate;
    int maxSold = 0, minSold = 0;
    int maxSoldId, minSoldId;

    // 사용자로부터 상품 개수 입력
    printf("상품 개수를 입력하세요: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_PRODUCTS) {
        printf("상품 개수는 1에서 100 사이여야 합니다.\n");
        return 1;
    }

    Product products[MAX_PRODUCTS];

    // 각 상품의 정보 입력
    for (i = 0; i < n; i++) {
        products[i].id = i + 1; // 고유 ID는 1부터 시작
        printf("상품 ID %d의 입고 수량을 입력하세요: ", products[i].id);
        scanf("%d", &products[i].stock);
        
        printf("상품 ID %d의 판매 수량을 입력하세요: ", products[i].id);
        scanf("%d", &products[i].sold);

        // 남은 재고 계산
        products[i].remaining = products[i].stock - products[i].sold;

        // 입력 값이 올바른지 확인
        if (products[i].remaining < 0) {
            printf("판매 수량이 입고 수량보다 클 수 없습니다.\n");
            return 1;
        }

        // 총 입고 수량과 총 판매 수량 계산
        totalStock += products[i].stock;
        totalSold += products[i].sold;

        // 가장 많이 판매된 상품과 적게 판매된 상품 계산
        if (i == 0 || products[i].sold > maxSold) {
            maxSold = products[i].sold;
            maxSoldId = products[i].id;
        }
        if (i == 0 || products[i].sold < minSold) {
            minSold = products[i].sold;
            minSoldId = products[i].id;
        }
    }

    // 총 판매량과 판매율 계산
    salesRate = (float)totalSold / totalStock * 100;

    // 상품 별 재고 출력
    printf("\n상품 별 남은 재고:\n");
    for (i = 0; i < n; i++) {
        printf("상품 ID %d - 남은 재고: %d\n", products[i].id, products[i].remaining);
    }

    // 총 판매량과 판매율 출력
    printf("\n총 판매량: %d\n", totalSold);
    printf("판매율: %.2f%%\n", salesRate);

    // 가장 많이, 가장 적게 판매된 상품 ID 출력
    printf("\n가장 많이 판매된 상품 ID: %d (판매량: %d)\n", maxSoldId, maxSold);
    printf("가장 적게 판매된 상품 ID: %d (판매량: %d)\n", minSoldId, minSold);

    // 재고 부족 상품 출력
    printf("\n재고 부족 상품 목록:\n");
    int stockWarning = 0;
    for (i = 0; i < n; i++) {
        if (products[i].remaining <= 2) {
            printf("상품 ID %d (남은 재고: %d)\n", products[i].id, products[i].remaining);
            stockWarning = 1;
        }
    }
    
    // 재고 부족 상품이 없을 경우 출력
    if (!stockWarning) {
        printf("재고 부족인 상품이 없습니다.\n");
    }

    return 0;
}
