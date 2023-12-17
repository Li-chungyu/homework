#include <stdio.h>
#include <string.h>

int main(){
	int m = 0, n = 0, i = 0, j = 0, avg = 0, sum = 0, sid = 1, count = 0, student_id = 0, num_no_pass = 0, students = 0;
	
	scanf("%d %d", &m, &n);
	int course[m][6], scores[n][2];
	memset(course, 0, sizeof(course));
	memset(scores, 0, sizeof(scores));
	
	for(i = 0; i < m; ++i){
		scanf("%d %d %d", &course[i][0], &course[i][1], &course[i][2]);
	}
	
	for(i = 0; i < n; ++i){
		scanf("%d %d", &scores[i][0], &scores[i][1]);
	}
	
	i = 0;
	while(sid <= m){
		count = 0;
		sum = 0;
		while(i < n){
			if(scores[i][0] == sid){
				sum += scores[i][1];
				++i;
				++count;
			}
			else{
				avg = sum / count;
				course[sid-1][3] = avg;
				++sid;
				break;
			}
		}
		if(i == n){
			avg = sum / count;
	    	course[sid-1][3] = avg;
	    	break;
		}
	}

	
	for(i = 0; i < m; ++i){
		if(course[i][3] < 60 && course[i][4] != 2){
			course[i][4] = 1; 
			student_id = course[i][1];
			for(j = i+1; j < m; ++j){
				if(course[j][1] == student_id)
					course[j][4] = 2;
			}
		}
	}

	for(i = 0; i < m; ++i){
		if(course[i][5] == 0){
			course[i][5] = 1;
			student_id = course[i][1];
			for(j = i+1; j < m; ++j){
				if(course[j][1] == student_id && course[j][5] == 0)
					course[j][5] = 2;
			}
		}	
	}
	
	for(i = 0; i < m; ++i){
		if(course[i][4] == 1) ++num_no_pass;
		if(course[i][5] == 1) ++students;
	}
	
	printf("%d %d", students, num_no_pass);

	return 0;
}