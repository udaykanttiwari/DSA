#include "testUtils.h"
#include "doublyLinkedList.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
list* start;


void tearDown(){
    printf("\ncoming yar\n");
       dispose(start);
}

void test_create_should_assign_null_to_head_and_0_to_length(){
        start = create();
        ASSERT(start->head == NULL);
        ASSERT(start->length == 0);
 };

void test_insert_should_insert_first_node(){
         int element = 100, answer;
         start = create();
         answer = insert(start,1,&element);
         ASSERT(answer == 1);
        ASSERT(start->length == 1);
};

void test_insert_should_insert_node_in_the_frist_position(){
         int element = 100, element2 = 200,answer;
         start = create();
         answer = insert(start,1,&element);
         answer = insert(start,1,&element2);
         ASSERT(answer == 1);
        ASSERT(start->length == 2);

};

void test_insert_should_insert_node_in_the_last_position(){
         int element = 100, element2 = 200,answer;
         start = create();
         answer = insert(start,1,&element);
         answer = insert(start,1,&element2);
         answer = insert(start,3,&element2);
          ASSERT(answer == 1);
        ASSERT(start->length == 3);

};

void test_insert_should_return_0_when_index_is_more_than_required_index(){
        int answer,element=10;
        start = create();
        answer = insert(start,5,&element);
        ASSERT(answer==0);
        ASSERT(start->length == 0);

};

void test_insert_should_return_1_if_element_inserted_in_the_middle(){
        int answer,element=10;
        start = create();
        answer = insert(start,1,&element);
        answer = insert(start,2,&element);
        answer = insert(start,3,&element);
        answer = insert(start,2,&element);
        ASSERT(answer==1);
        ASSERT(start->length == 4);

};

void test_Remove_should_delete_the_first_element(){
        int answer;
        int element = 10;
        int element2 = 20;
        start = create();
        insert(start,1,&element);
        insert(start,2,&element);
        insert(start,3,&element2);
        answer = Remove(start,1);
        ASSERT(answer == 1);
        ASSERT(start->length == 2);
}

void test_Remove_should_delete_the_last_element(){
        int answer;
        int element = 190;
        int element2 = 200;
        start = create();
        insert(start,1,&element);
        insert(start,2,&element);
        insert(start,3,&element2);
        answer = Remove(start,3);
        ASSERT(answer == 1);
        ASSERT(start->length == 2);        
}
void test_Remove_should_delete_the_middle_element(){
        int answer;
        int element = 190;
        int element2 = 200;
        start = create();
        insert(start,1,&element);
        insert(start,2,&element);
        insert(start,3,&element2);
        insert(start,4,&element2);
        answer = Remove(start,2);
        ASSERT(answer == 1);
        ASSERT(start->length == 3);        
}

void test_length_should_return_the_totel_no_of_elements(){
        int answer;
        int element = 190;
        int element2 = 200;
        start = create();
        insert(start,1,&element);
        insert(start,2,&element);
        insert(start,3,&element2);
        insert(start,4,&element2);
        ASSERT(answer == 4);
}

void test_findIndex_should_return_the_position_of_element_in_list(){
        int answer;
        int element = 190;
        int element2 = 200;
        int element3 = 200;
        start = create();
        insert(start,1,&element);
        insert(start,2,&element2);
        insert(start,3,&element3);
        answer = findIndex(start,&element2,sizeof(int));
        ASSERT(answer == 2);        
}

void test_findIndex_should_return_0_if_element_not_found(){
        int answer;
        int element = 190;
        int element2 = 200;
        int element3 = 200;
        int element4 = 50;
        start = create();
        insert(start,1,&element);
        insert(start,2,&element2);
        insert(start,3,&element3);
        answer = findIndex(start,&element4,sizeof(int));
        ASSERT(answer == 0);        
};