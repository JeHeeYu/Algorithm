#include <stdio.h>
#include <string.h>

int main(void) {

    char arr[101];
    scanf("%s", arr);
    int len, sum; 

    len = strlen(arr);  
    sum = strlen(arr); 
    for (int i = 0; i < len; i++) 
    {   
        if (arr[i] == 'c' || arr[i] == 's' || arr[i] == 'z') 
        {  
            if (arr[i + 1] == '=' || arr[i + 1] == '-') 
                sum--;  
        }
        else if (arr[i] == 'n' || arr[i] == 'l') 
        {  
            if (arr[i + 1] == 'j') 
                sum--;  
        }
        else if (arr[i] == 'd') 
        {  
            if (arr[i + 1] == '-') 
                sum--;  
            else if (arr[i + 1] == 'z' && arr[i + 2] == '=') 
                sum--; 
        }
    }

    printf("%d\n", sum); 

    return 0;
}
