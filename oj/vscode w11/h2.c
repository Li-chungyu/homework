/*************************************************************
function name: convertToDifferentBase
description: Convert a decimal number @dec to the number with different @base and store the result as a string in result
return vaule: Result after convert.
notice: The letter you see in the number should be upper case.
*************************************************************/
char *convertToDifferentBase(int dec, int base, char *result) {
	int num[32];
  	int i=0;
  	if(dec<2147483647){
    	while(dec>0){
    		num[i] = dec % base; 
    		dec = dec/base;
      		i++;
    	}
      	int k=0;
      	for(int j=i-1;j>=0;j--){
    		if(num[j]<10){
            	result[k] = (char)(num[j]+'0');
            }
          	else{
            	result[k] = (char)(num[j]-10+'A');
            }
          	k++;
    	}
      		result[i]='\0';
    }
  	
  	return result;
}