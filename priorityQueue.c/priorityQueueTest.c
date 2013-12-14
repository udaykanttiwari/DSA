#include "testUtils.h"
#include "priorityQueue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

list* listPtr;

void tearDown(){
        free(listPtr);
}

void test_create_should_create_a_head_with_null(){
        listPtr = create();
        ASSERT(listPtr->length == 0);
        ASSERT(listPtr->head == NULL );
}

void test_enqueue_should_insert_first_int_element_with_priority(){
        int answer;
        int data = 100;
        listPtr = create();
        answer = enqueue(listPtr,2,&data);
        ASSERT(answer == 1);
        ASSERT(*(int*)listPtr->head->data == 100);
}

void test_enqueue_should_insert_first_float_element_with_priority(){
        int answer;
        float data = 10.50;
        listPtr = create();
        answer = enqueue(listPtr,2,&data);
        ASSERT(answer == 1);
        ASSERT(*(float*)listPtr->head->data == 10.50f);
}

void test_enqueue_should_insert_first_double_element_with_priority(){
        int answer;
        double data = 10.509;
        listPtr = create();
        answer = enqueue(listPtr,2,&data);
        ASSERT(answer == 1);
        ASSERT(*(double*)listPtr->head->data == 10.509);
}

void test_enqueue_should_insert_second_int_element_priorty_in_sorted_order(){
        int answer;
        int data=100;
        int data1=150;
        listPtr=create();
        answer = enqueue(listPtr,2,&data);
        answer = enqueue(listPtr,1,&data1);
        ASSERT(answer==1);
        ASSERT(*(int*)listPtr->head->data==150);
        ASSERT(*(int*)listPtr->head->next->data==100);
};

void test_enqueue_should_insert_multiple_int_elements_at_first(){
        int answer;
        int data1=100;
        int data2=150;
        int data3=200;
        int data4=250;
        int data5=300;
        listPtr=create();
        answer = enqueue(listPtr,5,&data1);
        answer = enqueue(listPtr,4,&data2);
        answer = enqueue(listPtr,3,&data3);
        answer = enqueue(listPtr,2,&data4);
        answer = enqueue(listPtr,1,&data5);
        ASSERT(answer==1);
        ASSERT(*(int*)listPtr->head->data==300);
        ASSERT(*(int*)listPtr->head->next->data==250);
}

void test_enqueue_should_insert_multiple_double_elements_at_first(){
        int answer;
        double data1=100;
        double data2=150;
        double data3=200;
        double data4=250;
        double data5=300;
        listPtr=create();
        answer = enqueue(listPtr,5,&data1);
        answer = enqueue(listPtr,4,&data2);
        answer = enqueue(listPtr,3,&data3);
        answer = enqueue(listPtr,2,&data4);
        answer = enqueue(listPtr,1,&data5);
        ASSERT(answer==1);
        ASSERT(*(double*)listPtr->head->data==300);
        ASSERT(*(double*)listPtr->head->next->data==250);
}

void test_enqueue_should_insert_int_element_in_middle(){
        int answer;
        int data1=100;
        int data2=150;
        int data3=200;
        int data4=250;
        int data5=300;
        listPtr=create();
        answer = enqueue(listPtr,4,&data2);
        answer = enqueue(listPtr,2,&data4);
        answer = enqueue(listPtr,1,&data5);
        answer = enqueue(listPtr,3,&data3);
        ASSERT(answer==1);
        ASSERT(*(int*)listPtr->head->next->next->data=200);
}

void test_enqueue_should_insert_float_element_in_middle(){
        int answer;
        float data1=10.5;
        float data2=15.5;
        float data3=20.5;
        float data4=25.5;
        float data5=30.5;
        listPtr=create();
        answer = enqueue(listPtr,4,&data2);
        answer = enqueue(listPtr,2,&data4);
        answer = enqueue(listPtr,1,&data5);
        answer = enqueue(listPtr,3,&data3);
        ASSERT(answer==1);
        ASSERT(*(float*)listPtr->head->next->next->data=20.5);
}

void test_enqueue_should_insert_char_element_in_middle(){
        int answer;
        char data1='a';
        char data2='b';
        char data3='c';
        char data4='d';
        char data5='e';
        listPtr=create();
        answer = enqueue(listPtr,4,&data2);
        answer = enqueue(listPtr,2,&data4);
        answer = enqueue(listPtr,1,&data5);
        answer = enqueue(listPtr,3,&data3);
        ASSERT(answer==1);
        ASSERT(*(char*)listPtr->head->next->next->data='c');
}

void test_enqueue_should_insert_two_int_element_in_middle(){
        int answer;
        int data1=100;
        int data2=150;
        int data3=200;
        int data4=250;
        listPtr=create();
        answer = enqueue(listPtr,1,&data2);
        answer = enqueue(listPtr,5,&data4);
        answer = enqueue(listPtr,2,&data1);
        answer = enqueue(listPtr,3,&data3);
        ASSERT(answer == 1);
        ASSERT(*(int*)listPtr->head->next->data == 100);
        ASSERT(*(int*)listPtr->head->next->next->data == 200);
}


void test_enqueue_should_insert_int_element_of_same_priorty(){
        int answer;
        int data=100;
        int data1=150;
        listPtr=create();
        answer = enqueue(listPtr,2,&data);
        answer = enqueue(listPtr,2,&data1);
answer = enqueue(listPtr,4,&data1);
ASSERT(answer==1);
ASSERT(*(int*)listPtr->head->data==100);
ASSERT(*(int*)listPtr->head->next->data==150);
};

void test_enqueue_should_insert_float_element_of_same_priorty(){
        int answer;
        float data=10.5;
        float data1=15.5;
        float data2=20.5;
        listPtr=create();
        answer = enqueue(listPtr,2,&data);
        answer = enqueue(listPtr,2,&data1);
        answer = enqueue(listPtr,2,&data2);
ASSERT(answer==1);
ASSERT(*(float*)listPtr->head->data==10.5f);
};

void test_enqueue_should_insert_integer_element_of_decreasing_priority(){
        int answer;
        int data=12;
        int data1=100;
        int data3=200;
        int data4=300;
        listPtr=create();
        answer = enqueue(listPtr,1,&data);
        answer = enqueue(listPtr,2,&data1);
        answer = enqueue(listPtr,3,&data3);
        answer = enqueue(listPtr,4,&data4);
        ASSERT(*(int *)listPtr->head->data==12);
        ASSERT(*(int *)listPtr->head->next->data==100);
        ASSERT(*(int *)listPtr->head->next->next->data==200);
        ASSERT(*(int *)listPtr->head->next->next->next->data==300);
};

void test_enqueue_should_insert_char_element_of_decreasing_priority(){
        int answer;
        char data='a';
        char data1='b';
        char data3='c';
        char data4='d';
        listPtr=create();
        answer = enqueue(listPtr,1,&data);
        answer = enqueue(listPtr,2,&data1);
        answer = enqueue(listPtr,3,&data3);
        answer = enqueue(listPtr,4,&data4);
        ASSERT(*(char *)listPtr->head->data='a');
        ASSERT(*(char *)listPtr->head->next->data='b');
        ASSERT(*(char *)listPtr->head->next->next->data='c');
        ASSERT(*(char *)listPtr->head->next->next->next->data='d');
};

void test_enqueue_should_insert_double_element_of_decreasing_priority(){
        int answer;
        double data=10.2;
        double data1=20.2;
        double data3=30.2;
        double data4=40.2;
        listPtr=create();
        answer = enqueue(listPtr,1,&data);
        answer = enqueue(listPtr,2,&data1);
        answer = enqueue(listPtr,3,&data3);
        answer = enqueue(listPtr,4,&data4);
        ASSERT(*(double *)listPtr->head->data=10.2);
        ASSERT(*(double *)listPtr->head->next->data=20.2);
        ASSERT(*(double *)listPtr->head->next->next->data=30.2);
        ASSERT(*(double *)listPtr->head->next->next->next->data=40.2);
        }

void test_should_dequeue_int_element_of_higest_priority(){
        int answer;
        int data=12;
        int data1=100;
        int data3=200;
        int data4=300;
        listPtr=create();
        enqueue(listPtr,1,&data);
        enqueue(listPtr,2,&data1);
        enqueue(listPtr,3,&data3);
        enqueue(listPtr,4,&data4);
        answer = dequeue(listPtr);
        ASSERT(answer == 1);
        ASSERT(*(int *)listPtr->head->data==100);
}

void test_should_dequeue_float_element_of_higest_priority(){
        int answer;
        float data=12;
        float data1=100;
        float data3=200;
        float data4=300;
        listPtr=create();
        enqueue(listPtr,1,&data);
        enqueue(listPtr,2,&data1);
        enqueue(listPtr,3,&data3);
        enqueue(listPtr,4,&data4);
        answer = dequeue(listPtr);
        ASSERT(answer == 1);
        ASSERT(*(float *)listPtr->head->data==100);
}

void test_should_dequeue_char_element_of_higest_priority(){
        int answer;
        char data1='a';
        char data2='b';
        char data3='c';
        char data4='d';
        listPtr=create();
        enqueue(listPtr,1,&data2);
        enqueue(listPtr,5,&data4);
        enqueue(listPtr,2,&data1);
        enqueue(listPtr,3,&data3);
        answer = dequeue(listPtr);
        ASSERT(answer == 1);
        ASSERT(*(char*)listPtr->head->data ='a');
}