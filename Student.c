 #include<stdio.h>

 typedef struct{

     char name[50];
     int rollno;
     char grade;
 } Student;

 int main(){
     int n;
     printf("Enter the number of students: ");
     scanf("%d",&n);
     Student students[n];
     readStudents(students, n);
     sortStudentsByRollNo(students, n);
     displayStudents(students, n);
     return 0;
 }

 void readStudents(Student students[50],int n){
     char buffer[100];
     for(int i=0;i<n;i++){
        printf("Enter the student's name: \n");
        scanf("%s",  students[i].name);
        printf("Enter the student's Roll No. : \n");
        scanf("%d",  &students[i].rollno);
        fgets(buffer, sizeof(buffer), stdin);
        printf("Enter the student's grade:  \n");
        scanf("%c",  &students[i].grade);
     }

 }

 void displayStudents(Student students[], int n){
     for(int i=0;i<n;i++){
        printf("Name: %s\n", students[i].name);
        printf("Roll No. : %d\n", students[i].rollno);
        printf("Grade: %c\n", students[i].grade);
     }

 }

 void sortStudentsByRollNo(Student students[], int count) {
    Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].rollno > students[j + 1].rollno) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
 }
