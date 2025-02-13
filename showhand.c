#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef enum Suit {
  SPADES, 
  HEARTS,
  CLUBS,
  DIAMONDS 
} Suit;

typedef enum Face {
  ACE,
  DEUCE,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
  TEN,
  JACK,
  QUEEN,
  KING
} Face;

typedef struct Card {
  Suit suit;
  Face face;
} Card;

typedef Card Hand[5];

int Order(Face face) {
  if (face == DEUCE) 
    return 2;
  if (face == THREE) 
    return 3;
  if (face == FOUR) 
    return 4;
  if (face == FIVE) 
    return 5;
  if (face == SIX) 
    return 6;
  if (face == SEVEN) 
    return 7;
  if (face == EIGHT) 
    return 8;
  if (face == NINE) 
    return 9;
  if (face == TEN) 
    return 10;
  if (face == JACK) 
    return 11;
  if (face == QUEEN) 
    return 12;
  if (face == KING) 
    return 13;
  if (face == ACE) 
    return 14;
  return 0;
}

int OrderSuit(Suit suit) {
  if (suit == SPADES) 
    return 4;
  if (suit == CLUBS) 
    return 2;
  if (suit == DIAMONDS)
    return 1;
  if (suit == HEARTS)
    return 3;
  return 0;
}

void PrintCard(Card card) {
  if (card.face == ACE) {
    printf("Ace");
  }
  if (card.face == DEUCE) {
    printf("Deuce");
  }
  if (card.face == THREE) {
    printf("Three");
  }
  if (card.face == FOUR) {
    printf("Four");
  }
  if (card.face == FIVE) {
    printf("Five");
  }
  if (card.face == SIX) {
    printf("Six");
  }
  if (card.face == SEVEN) {
    printf("Seven");
  }
  if (card.face == EIGHT) {
    printf("Eight");
  }
  if (card.face == NINE) {
    printf("Nine");
  }
  if (card.face == TEN) {
    printf("Ten");
  }
  if (card.face == JACK) {
    printf("Jack");
  }
  if (card.face == QUEEN) {
    printf("Queen");
  }
  if (card.face == KING) {
    printf("King");
  }

  printf(" of ");

  if (card.suit == SPADES) {
    printf("Spades");
  }
  if (card.suit == HEARTS) {
    printf("Hearts");
  }
  if (card.suit == DIAMONDS) {
    printf("Diamonds");
  }
  if (card.suit == CLUBS) {
    printf("Clubs");
  }
}
bool InputHand(Hand hand) {
  char faceinput[100];
  char suitinput[100];
  char temp_faceinput[5][100];
  char temp_suitinput[5][100];
  int i = 0;
  int count = 0;
  while (1) {
    scanf("%s", temp_suitinput[count]);
    if (temp_suitinput[count][0] == '-' && temp_suitinput[count][1] == '1') {
      break;
    }
    scanf("%s", temp_faceinput[count]);
    count++;
  }
  if (count != 5)
    return false;

  else {
    while (i < 5) {
      Suit suit;
      Face face;
      if (temp_suitinput[i][0] == 'H') 
        suit = HEARTS;
      else if (temp_suitinput[i][0] == 'S') 
        suit = SPADES;
      else if (temp_suitinput[i][0] == 'C') 
        suit = CLUBS;
      else if (temp_suitinput[i][0] == 'D') 
        suit = DIAMONDS;
    

      if (temp_faceinput[i][0] == 'A')
        face = ACE;
      else if (temp_faceinput[i][0] == '2') 
        face = DEUCE;
      else if (temp_faceinput[i][0] == '3') 
        face = THREE;
      else if (temp_faceinput[i][0] == '4') 
        face = FOUR;
      else if (temp_faceinput[i][0] == '5') 
        face = FIVE;
      else if (temp_faceinput[i][0] == '6') 
        face = SIX;
      else if (temp_faceinput[i][0] == '7') 
        face = SEVEN;
      else if (temp_faceinput[i][0] == '8') 
        face = EIGHT;
      else if (temp_faceinput[i][0] == '9') 
        face = NINE;
      else if (temp_faceinput[i][0] == '1' && temp_faceinput[i][1] == '0') 
        face = TEN;
      else if (temp_faceinput[i][0] == 'J') 
        face = JACK;
      else if (temp_faceinput[i][0] == 'Q') 
        face = QUEEN;
      else if (temp_faceinput[i][0] == 'K') 
        face = KING;
      else
        return true;

      hand[i].suit = suit;
      hand[i].face = face;
      i++;
    }
  }
  return true;
}

void PrintHand(Hand hand) {
  for (int i = 0; i < 5; i++) {
    PrintCard(hand[i]);
  }

}

bool BiggerThan(Card card1, Card card2) {
  int card1_suit = OrderSuit(card1.suit);
  int card1_face = Order(card1.face);
  int card2_suit = OrderSuit(card2.suit);
  int card2_face = Order(card2.face);

  if (card1_face > card2_face) {
    return true;
  }

  else if (card1_face < card2_face) {
    return false;
  }

  else {
  
    if (card1_suit > card2_suit) {
      return true;
    }
  
    else if (card1_suit < card2_suit) {
      return false;
    }
  }
}
Card FindLargest(Hand hand) {
  Card max_num = hand[0];
  bool ace = false;
  bool deuce = false;
  bool three = false;
  bool four = false;
  bool five = false;

  for (int i = 0; i < 5; i++) {
    if (hand[i].face == ACE)
      ace = true;
    if (hand[i].face == DEUCE)
      deuce = true;
    if (hand[i].face == THREE)
      three = true;
    if (hand[i].face == FOUR)
      four = true;
    if (hand[i].face == FIVE)
      five = true;
  }

  if (ace && deuce && three && four && five) {
    for (int i = 0; i < 5; i++) {
      if (hand[i].face == FIVE)
        return hand[i];
    }
  }
  

  for (int i = 1; i < 5; i++) {
    if (BiggerThan(hand[i], max_num)) {
      max_num = hand[i];
    }
  }
  return max_num;
}




bool IsStraight(Hand hand) {
  Face num;
  Card max_num;
  int first_num;
  int arr[15] = {0};
  int arr_suit[5] = {0};
  int count = 0;
  for (int i = 0; i < 5; i++) {
    num = Order(hand[i].face);
    int num1 = OrderSuit(hand[i].suit);
    arr[num]++;
    arr_suit[num1]++;
  }
  for (int i = 1; i < 5; i++) {
    if (arr_suit[i] == 5) {
      count++;
    }
  }
  if (count != 0)
    return false;
  
  if (arr[14] == 1 && arr[2] == 1 && arr[3] == 1  &&
      arr[4] == 1  && arr[5] == 1 ) {
    
    max_num = FindLargest(hand);
    Card temp = hand[0];
    hand[0] = max_num;
    max_num = temp;
    return true;
  }

  for (int i = 2; i <= 14; i++) {
    if (arr[i] == 1) {
      first_num = i;
      break;
    }
  }
  for (int i = first_num; i < first_num + 5; i++) {
    if (arr[i] != 1) {
      return false;
    }
  }
  max_num = FindLargest(hand);
  Card temp = hand[0];
  hand[0] = max_num;
  max_num = temp;

  return true;
}



bool IsFlush(Hand hand) {
  Card card;
  bool is_same_suit = true; 
  Card max_num;
  bool is_straight = false;
  int num1;
  int num;
  int arr[15] = {0};
  int arr_suit[5] = {0};
  int first_num;
  for (int i = 0; i < 4; i++) {
    if (hand[i].suit != hand[i+1].suit) {
      is_same_suit = false;
      break;
    }
  }
  
  
  for (int i = 0; i < 5; i++) {
    num = Order(hand[i].face);
    num1 = OrderSuit(hand[i].suit);
    arr[num]++;
    arr_suit[num1]++;
  }
  if (arr[14] == 1 && arr[2] == 1 && arr[3] == 1  &&
      arr[4] == 1  && arr[5] == 1 ) {
    is_straight = true;
  }

  for (int i = 2; i <= 14; i++) {
    if (arr[i] == 1) {
      first_num = i;
      break;
    }
  }
  if (arr[first_num] == 1 && arr[first_num+1] == 1 && arr[first_num+2] == 1 &&
      arr[first_num+3] == 1 && arr[first_num+4] == 1) {
    is_straight = true;
  }
  
  if (!is_straight && is_same_suit) {
    max_num = FindLargest(hand);
    Card temp = hand[0];
    hand[0] = max_num;
    max_num = temp;
    return true;
  }
  
  return false;
  
}




bool IsStraightFlush(Hand hand) {
  bool is_flush = true;
  Card max_num;
  bool is_straight = false;
  int num;
  int num1;
  int arr[15] = {0};
  int arr_suit[5] = {0};
  int first_num;
  for (int i = 0; i < 4; i++) {
    if (hand[i].suit != hand[i+1].suit) {
      is_flush = false;
      return false;
    }
  }
  
  
  for (int i = 0; i < 5; i++) {
    num = Order(hand[i].face);
    num1 = OrderSuit(hand[i].suit);
    arr[num]++;
    arr_suit[num1]++;
  }
  if (arr[14] == 1 && arr[2] == 1 && arr[3] == 1  &&
      arr[4] == 1  && arr[5] == 1 ) {
    is_straight = true;
  }

  for (int i = 2; i <= 14; i++) {
    if (arr[i] == 1) {
      first_num = i;
      break;
    }
  }
  for (int i = first_num; i < first_num + 5; i++) {
    if (arr[first_num] == 1 && arr[first_num+1] == 1 && arr[first_num+2] == 1 &&
        arr[first_num+3] == 1 && arr[first_num+4] == 1) {
      is_straight = true;
    }
  }
  
  if (is_flush && is_straight) {
    max_num = FindLargest(hand);
    Card temp = hand[0];
    hand[0] = max_num;
    max_num = temp;
    return true;
  }

  else {
    return false;
  }

}

bool IsFourOfAKind(Hand hand) {
  bool is_four_same = false;
  bool has_four_suit = true;
  int arr[15]={0};
  int suit_arr[5]={0};
  for (int i = 0; i <= 4; i++) {
    int num = Order(hand[i].face);
    int suit = OrderSuit(hand[i].suit);
    arr[num]++;
    suit_arr[suit]++;
  }

  for (int i = 1; i < 5; i++) {
    if (suit_arr[i] == 1 || suit_arr[i] == 2) {
      has_four_suit = true;
    }

    else {
      return false;
    }
  }

  int index;
  for (int i = 2; i <= 14 ; i++) {
    if (arr[i] == 4) {
      index = i;
      is_four_same = true;
      break;
    }
  }
  if (is_four_same == false) {
    return false;
  }
  Card largest;
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (Order(hand[i].face) == index) {
      largest = hand[i];
      count = i;
      break;
    }
  }
  for (int i = count; i < 5; i++) {
    if (Order(hand[i].face) == index) {
      if (OrderSuit(hand[i].suit) > OrderSuit(largest.suit)) {
        largest = hand[i];
      }
    }
  }
  Card temp = largest;
  largest = hand[0];
  hand[0] = temp;
  return true;
}

bool HasThreeOfAKind(Hand hand) {
  bool is_third_same = false;
  int arr[15] = {0};
  int suit_arr[5] = {0};
  for (int i = 0; i <= 4; i++) {
    int num = Order(hand[i].face);
    int suit = OrderSuit(hand[i].suit);
    arr[num]++;
    suit_arr[suit]++;
  }

  int index;
  for (int i = 2; i <= 14 ; i++) {
    if (arr[i] == 3) {
      index = i;
      is_third_same = true;
      break;
    }
  }
  if (!is_third_same) {
    return false;
  }
  for (int i = 2; i <= 14 ; i++) {
    if (arr[i] == 2) {
      return false;
    }
  }

  Card largest;
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (Order(hand[i].face) == index) {
      largest = hand[i];
      count = i;
      break;
    }
  }
  for (int i = count; i < 5; i++) {
    if (Order(hand[i].face) == index) {
      if (OrderSuit(hand[i].suit) > OrderSuit(largest.suit)) {
        largest = hand[i];
      }
    }
  }
  Card temp = largest;
  largest = hand[0];
  hand[0] = temp;
  return true;
}




bool IsFullHouse(Hand hand) {
  bool has_pair = false;
  bool has_third = false;
  int arr[15] = {0};
  int suit_arr[5] = {0};
  int third_num = 0;
  for (int i = 0; i <= 4; i++) {
    int num = Order(hand[i].face);
    int suit = OrderSuit(hand[i].suit);
    arr[num]++;
    suit_arr[suit]++;
  }
  
  for (int i = 2; i <= 14; i++) {
    if (arr[i] == 2) {
      has_pair = true;
      break;
    }
  }
  
  for (int i = 2; i <= 14; i++) {
    if (arr[i] == 3) {
      has_third = true;
      third_num = i;
      break;
    }
  }
  
  
  
  if (has_pair && has_third) {
    Card largest;
    int count = 0;
    for (int i = 0; i < 5; i++) {
      if (Order(hand[i].face) == third_num) {
        largest = hand[i];
        count = i;
        break;
      }
    }
    
    for (int i = count; i < 5; i++) {
      if (Order(hand[i].face) == third_num) {
        if (OrderSuit(hand[i].suit) > OrderSuit(largest.suit)) {
          largest = hand[i];
        }
      }
    }
    Card temp = largest;
    largest = hand[0];
    hand[0] = temp;
    return true;
  }
  return false;
  
}



bool IsTwoPairs(Hand hand) {
  Card ans_card[2] = {0};
  bool is_third_same = false;
  int arr[15] = {0};
  int suit_arr[5] = {0};
  int ans[2] = {0};
  int count_two_pair_num = 0;
  for (int i = 0; i < 5; i++) {
    int num = Order(hand[i].face);
    arr[num]++;
  }

  for (int i = 2; i <= 14 ; i++) {
    if (arr[i] == 2) {
      ans[count_two_pair_num] = i;
      count_two_pair_num++;
    }

    else if (arr[i] > 2) {
      return false;
    }
    
  }

  if (count_two_pair_num != 2) {
    return false;
  }

  for (int j = 0; j < count_two_pair_num; j++) {
    Card largest;
    int count = 0;
    for (int i = 0; i < 5; i++) {
      if (Order(hand[i].face) == ans[j]) {
        largest = hand[i];
        count = i;
        break;
      }
    }
    for (int i = count; i < 5; i++) {
      if (Order(hand[i].face) == ans[j]) {
        if (OrderSuit(hand[i].suit) > OrderSuit(largest.suit)) {
          largest = hand[i];
        }
      }
    }
    ans_card[j] = largest;
  }
  if (BiggerThan(ans_card[0], ans_card[1])) {
    Card temp = ans_card[0];
    ans_card[0] = hand[0];
    hand[0] = temp;
    temp = ans_card[1];
    ans_card[1] = hand[1];
    hand[1] = temp;
    return true;
  }

  else {
    Card temp = ans_card[1];
    ans_card[1] = hand[0];
    hand[0] = temp;
    temp = ans_card[0];
    ans_card[0] = hand[1];
    hand[1] = temp;
    return true;
  }
}




bool HasonePair(Hand hand) {
  bool is_two_same = false;
  int arr[15]={0};
  int suit_arr[5]={0};
  for (int i = 0; i <= 4; i++) {
    int num = Order(hand[i].face);
    int suit = OrderSuit(hand[i].suit);
    arr[num]++;
    suit_arr[suit]++;
  }

  int index;
  for (int i = 2; i <= 14 ; i++) {
    if (arr[i] == 2) {
      index = i;
      is_two_same = true;
      break;
    }
  }
  if (is_two_same == false || IsTwoPairs(hand) || IsFullHouse(hand)) {
    return false;
  }

  Card largest;
  int count = 0;
  for (int i = 0; i < 5; i++) {
    if (Order(hand[i].face) == index) {
      largest = hand[i];
      count = i;
      break;
    }
  }
  for (int i = count; i < 5; i++) {
    if (Order(hand[i].face) == index) {
      if (OrderSuit(hand[i].suit) > OrderSuit(largest.suit)) {
        largest = hand[i];
      }
    }
  }
  Card temp = largest;
  largest = hand[0];
  hand[0] = temp;
  return true;
}


void Highcard(Hand hand) {
  Card max_num = hand[0];
  for (int i = 1; i < 5; i++) {
    if (Order(hand[i].face) > Order(max_num.face)) {
      max_num = hand[i];
    }
  }
  Card temp = max_num;
  max_num = hand[0];
  hand[0] = temp;
}

int WhichConbine(Hand hand) {
  if (IsStraightFlush(hand)) {
    return 8;
  }
  if (IsFourOfAKind(hand)) {
    return 7;
  }
  if (IsFullHouse(hand)) {
    return 6;
  }
  if (IsFlush(hand)) {
    return 5;
  } 
  if (IsStraight(hand)) {
    return 4;
  } 
  if (HasThreeOfAKind(hand)) {
    return 3;
  } 
  if (IsTwoPairs(hand)) {
    return 2;
  }
  if (HasonePair(hand)) {
    return 1;
  }
  return 0;
}
void Printhand1(int num) {
  if (num == 0) {
    printf("zilch ");
  }
  if (num == 1) {
    printf("one pair ");
  }
  if (num == 2) {
    printf("two pairs ");
  }
  if (num == 3) {
    printf("three of a kind ");
  }
  if (num == 4) {
    printf("straight ");
  }
  if (num == 5) {
    printf("flush ");
  }
  if (num == 6) {
    printf("full house ");
  }
  if (num == 7) {
    printf("four of a kind ");
  }
  if (num == 8) {
    printf("straight flush ");
  }
}
void Printhand(int num) {
  if (num == 0) {
    printf("Zilch ");
  }
  if (num == 1) {
    printf("One pair ");
  }
  if (num == 2) {
    printf("Two pairs ");
  }
  if (num == 3) {
    printf("Three of a kind ");
  }
  if (num == 4) {
    printf("Straight ");
  }
  if (num == 5) {
    printf("Flush ");
  }
  if (num == 6) {
    printf("Full house ");
  }
  if (num == 7) {
    printf("Four of a kind ");
  }
  if (num == 8) {
    printf("Straight flush ");
  }
}


void Num1maxcard(int num, Hand hand) {
  bool is;
  Card max_num;
  if (num == 0) {
    Highcard(hand); 
  }
  if (num == 2) {
    is = IsTwoPairs(hand);
  }
  if (num == 1) {
    is = HasonePair(hand);
  }
  if (num == 3) {
    is = HasThreeOfAKind(hand);
  }
  if (num == 4) {
    is = IsStraight(hand);
  }
  if (num == 5) {
    is = IsFlush(hand);
  }
  if (num == 6) {
    is = IsFullHouse(hand);
  }
  if (num == 7) {
    is = IsFourOfAKind(hand);
  }
  if (num == 8) {
    is = IsStraightFlush(hand);
  }
}


bool Twopaircompare(Hand hand, Hand hand1) {
  int hand_face0 = hand[0].face;
  int hand_suit0 = hand[0].suit;
  int hand_face1 = hand[1].face;
  int hand_suit1 = hand[1].suit;
  int hand1_face0 = hand1[0].face;
  int hand1_suit0 = hand1[0].suit;
  int hand1_face1 = hand1[1].face;
  int hand1_suit1 = hand1[1].suit;
    
  if (hand_face0 > hand1_face0) {
    return true;
  }

  else if (hand_face0 < hand1_face0) {
    return false;
  }

  else {
  
    if (hand_face1 > hand1_face1) {
      return true;
    }
  
    else if (hand_face1 < hand1_face1) {
      return false;
    }
  }
}


void Play(Hand hand1, Hand hand2) {
  int num1 = WhichConbine(hand1);
  int num2 = WhichConbine(hand2);
  int count = 0;
  bool num1_is_two_pair = false;
  bool num2_is_two_pair = false;
  Num1maxcard(num1, hand1);
  Num1maxcard(num2, hand2);

  if (num1 == 2) num1_is_two_pair = true;
  if (num2 == 2) num2_is_two_pair = true;

  if (num1_is_two_pair && !num2_is_two_pair) {
    Printhand(num1);
    printf("(");
    PrintCard(hand1[0]);
    printf(" and ");
    PrintCard(hand1[1]);
    if (num1 > num2) {
      printf(") wins over ");
    }

    else if (num2 > num1) {
      printf(") loses to ");
    }

    Printhand1(num2);
    printf("(");
    PrintCard(hand2[0]);
    printf(").");
    return;
  } 

  else if (!num1_is_two_pair && num2_is_two_pair) {
    Printhand(num1);
    printf("(");
    PrintCard(hand1[0]);
    if (num1 > num2) printf(") wins over ");
    else if (num2 > num1) printf(") loses to ");
    Printhand1(num2);
    printf("(");
    PrintCard(hand2[0]);
    printf(" and ");
    PrintCard(hand2[1]);
    printf(").");
    return;
  }

  else if (num1_is_two_pair && num2_is_two_pair) {
    Printhand(num1);
    printf("(");
    PrintCard(hand1[0]);
    printf(" and ");
    PrintCard(hand1[1]);
    if (Twopaircompare(hand1, hand2)) printf(") wins over ");
    else printf(") loses to ");

    Printhand1(num2);
    printf("(");
    PrintCard(hand2[0]);
    printf(" and ");
    PrintCard(hand2[1]);
    printf(").");  
    return;
  } 
  if (num1 > num2) {
    Printhand(num1);
    printf("(");
    PrintCard(hand1[0]);
    printf(") wins over ");
    Printhand1(num2);
    printf("(");
    PrintCard(hand2[0]);
    printf(").");
  } else if (num2 > num1) {
    Printhand(num1);
    printf("(");
    PrintCard(hand1[0]);
    printf(") loses to ");
    Printhand1(num2);
    printf("(");
    PrintCard(hand2[0]);
    printf(").");
  } else {
    if (BiggerThan(hand1[0], hand2[0])) {
      Printhand(num1);
      printf("(");
      PrintCard(hand1[0]);
      printf(") wins over ");
      Printhand1(num2);
      printf("(");
      PrintCard(hand2[0]);
      printf(").");
    } else {
      Printhand(num1);
      printf("(");
      PrintCard(hand1[0]);
      printf(") loses to ");
      Printhand1(num2);
      printf("(");
      PrintCard(hand2[0]);
      printf(").");
    }
  }
}


int main() {
  Hand firsthand, secondhand;

  if (InputHand(firsthand)) {
    if (InputHand(secondhand)) {
      Play(firsthand, secondhand);
    } else   // second input set not okay
      printf("Input Error in second hand of cards!\n");
  } else {  // first input set not okay
    printf("Input Error in first hand of cards!\n");
  }
  return 0;
}



