#include <stdio.h>
#include <string.h>
void rotate(int arr[26])
{
    int temp=arr[0];
    int i=0;
    for(i=0;i<25;i++)
    {
        arr[i]=arr[i+1];

    }
    arr[25]=temp;
}
int main(void) {
	// your code goes here

	///////////////////////////// defining the rotors //////////////////////////////////////////////////
    int fast_rotor_array2[26] = {16,3,5,7,9,11,13,4,17,19,21,25,23,1,15,26,6,10,24,8,2,12,14,22,20,18};

	int medium_rotor_array2[26] = {23,12,9,2,18,6,22,15,3,5,14,21,11,4,20,16,25,19,26,8,24,7,10,13,17,1};

	int slow_rotor_array2[26] = {17,5,11,6,14,16,25,15,12,10,7,18,26,19,9,20,1,22,2,4,23,3,24,21,8,13};
	////////////////////////////////////////////////////////////////////////////////////////////////////

	//////////////////////// defining the starting point of each rotor ////////////////////////////////
    int stp_fast = 14;
    int stp_medium = 15;
    int stp_slow = 16;
	///////////////////////////////////////////////////////////////////////////////////////////////////
    char confirm = 'Y';
    while(confirm == 'Y')
    {
        //the initial user choices displayed
        printf("***************************************************\n");
        printf("enter 1 - to enter the starting rotor letters\n");
        printf("enter 2 - to input a word to encrypt\n");
        printf("***************************************************\n");
        int choice=0;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: ;
            //Enter the initial rotor Configurations
            char r1;
            char r2;

            char r3;
            printf("enter the rotor configurations : ( fast medium slow)\n");
            scanf(" %c %c %c",&r1,&r2,&r3);
            int n1=r1-65;
            int n2=r2-65;
            int n3=r3-65;
            printf("%d %d %d\n",n1,n2,n3);
            while(fast_rotor_array2[0]!=(n1+1))
            {
            rotate(fast_rotor_array2);
            if(fast_rotor_array2[0]==stp_fast)
                rotate(medium_rotor_array2);
            }
              while(medium_rotor_array2[0]!=(n2+1))
            {
            rotate(medium_rotor_array2);
            if(medium_rotor_array2[0]==stp_medium)
                rotate(slow_rotor_array2);
            }
              while(slow_rotor_array2[0]!=(n3+1))
                rotate(slow_rotor_array2);

        break;

        case 2: ;

        printf("Enter the word to be encrypted :\n");
          char str[100];

	scanf("%s",str);
	char newstr[strlen(str)];
	int n=1;
            while(n<=strlen(str))
	{
	    char ch1 = str[n-1];
	    int i=0;
	    int index = ch1-65;
	    int temp = fast_rotor_array2[0];
	    if(fast_rotor_array2[0]==stp_fast)
            rotate(medium_rotor_array2);
        if(medium_rotor_array2[0]==stp_medium)
                rotate(slow_rotor_array2);
	    for(i=0;i<25;i++)
	    {
	        fast_rotor_array2[i]= fast_rotor_array2[i+1];
	    }
	    fast_rotor_array2[25]=temp;
	    int output1 = fast_rotor_array2[index];

	    int output2 = medium_rotor_array2[output1-1];

	    int output3 = slow_rotor_array2[output2-1];
	    int newoutput2=0;
	    int newoutput1=0;
	    int newoutput=0;
	    //reflector
	    switch (output3)
	    {
	        case 1:
	        output3 = 9;
	        break;
	         case 2:
	        output3 =24;
	        break;
	         case 3:
	        output3 =21;
	        break;
	         case 4:
	        output3 = 8;
	        break;
	         case 5:
	        output3 = 6;
	        break;
	         case 6:
	        output3 =5;
	        break;
	         case 7:
	        output3 =26;
	        break;
	         case 8:
	        output3 = 4;
	        break;
	         case 9:
	        output3 = 1;
	        break;
	         case 10:
	        output3 = 15;
	        break;
	         case 11:
	        output3 = 13;
	        break;
	         case 12:
	        output3 = 20;
	        break;
	         case 13:
	        output3 = 11;
	        break;
	         case 14:
	        output3 = 17;
	        break;
	         case 15:
	        output3 = 10;
	        break;
	         case 16:
	        output3 = 23;
	        break;
	         case 17:
	        output3 = 14;
	        break;
	         case 18:
	        output3 = 19;
	        break;
	         case 19:
	        output3 = 18;
	        break;
	         case 20:
	        output3 = 12;
	        break;
	         case 21:
	        output3 = 3;
	        break;
	         case 22:
	        output3 = 25;
	        break;
	         case 23:
	        output3 = 16;
	        break;
	         case 24:
	        output3 = 2;
	        break;
	         case 25:
	        output3 = 22;
	        break;
	         case 26:
	        output3 = 7;
	        break;
	    }
	    for(i=0;i<26;i++)
	    {
	        if(output3==slow_rotor_array2[i])
	        newoutput2=i+1;
	    }
	     for(i=0;i<26;i++)
	    {
	        if(newoutput2==medium_rotor_array2[i])
	        newoutput1=i+1;
	    }
	     for(i=0;i<26;i++)
	    {
	        if(newoutput1==fast_rotor_array2[i])
	        newoutput=i;
	    }
	    newstr[n-1]=(char)(65+newoutput);
	    n++;
	}
	printf("The encrypted word :-\n");
	printf("%s\n",newstr);
        }
        printf("Do you want to continue Y/N ?\n");
        scanf(" %c",&confirm);
    }
	return 0;
}
