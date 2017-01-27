#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <sys/time.h> 

int main();
typedef struct {
	char name[1000],roll[1000],email[1000],contact[100],pwd[100];
} stud;
typedef struct{
	char email[1000],pwd[100];
} admin;
typedef struct{
	int code;
	char sub[1000];
}subjects;
typedef struct{
	char q[10000],a[10],oa[100],ob[100],oc[100],od[100];
}qa;
typedef struct{
	char roll[1000];
	float mo,tm;
}stat;
/*int comparator(const void *p, const void *q) 
{
    int l = (((stat *)p)->mo)/(((stat *)p)->tm);
    int r = (((stat *)q)->mo)/(((stat *)q)->tm);
    return (r-l);
}*/
int partition (stat arr[], int low, int high)
{
    float pivot = arr[high].mo/arr[high].tm;    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j].mo/arr[j].tm <= pivot)
        {
            i++;    // increment index of smaller element
            stat x = arr[j];
            arr[j]=arr[i];
            arr[i]=x;

        }
    }
    //swap(&arr[i + 1], &arr[high]);
    stat x = arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=x;
    return (i + 1);
}

void quickSort(stat arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void reg_stud()
{
	int i;
	int n=0;
	stud a;
	stud data[1000];
	lbl3:printf("Enter your FIRST NAME ONLY\n");
	scanf("%s",a.name);
	printf("Enter your Roll Number\n");
	scanf("%s",a.roll);
	printf("Enter your email address\n");
	scanf("%s",a.email);
	printf("Enter your conatct\n");
	scanf("%s",a.contact);
	printf("Enter your Password\n");
	scanf("%s",a.pwd);
	FILE *fp,*read,*read2;
	read = fopen("profile_stud.txt","r");
	char email[1000];
	while(fscanf(read,"%s",email)==1)
	{
		strcpy(data[n].email,email);
		fscanf(read,"%s%s%s%s",data[n].pwd,data[n].name,data[n].contact,data[n].roll);
		n++;
	}
	for(i=0;i<n;i++)
	{
		if(strcmp(data[i].email,a.email)==0)
		{
			printf("Email Address Already exists, Try again\n");
			fclose(read);
			goto lbl3;
		}
	}
	read2 = fopen("profile_admin.txt","r");
	char waste[1000];
	while(fscanf(read2,"%s",email)==1)
	{
		if(strcmp(email,a.email)==0)
		{
			printf("Email Address Already exists, Try again\n");
			fclose(read2);
			goto lbl3;
		}
		fscanf(read2,"%s",waste);
	}
	fclose(read);
	fclose(read2);
	fp = fopen("profile_stud.txt","a");
	fprintf(fp,"%s %s %s %s %s\n",a.email,a.pwd,a.name,a.contact,a.roll);
	printf("Registered Succesfully!!\n");
	fclose(fp);
	

}
void reg_admin()
{
	//printf("dssf");
	int i,n=0;
	admin a;
	admin data[1000];
	lbl2:printf("Enter email address\n");
	scanf("%s",a.email);
	printf("Enter your password\n");
	scanf("%s",a.pwd);
	//printf("%s %s",a.email,a.pwd);
	//printf("asdfsjdf");
	FILE *fp,*read,*read2;
	read = fopen("profile_admin.txt","r");
	char email[1000];
	//printf("asdfsjdf");
	while(fscanf(read,"%s",email)==1)
	{
		strcpy(data[n].email,email);
		fscanf(read,"%s",data[n].pwd);
		n++;
	}
	for(i=0;i<n;i++)
	{
		//printf("%d\n",strcmp(data[i].email,a.email));
		if(strcmp(data[i].email,a.email)==0)
		{
			printf("Email Address Already exists, Try again\n");
			fclose(read);
			goto lbl2;
		}
	}
	//printf("%d\n",n);
	read2 = fopen("profile_stud.txt","r");
	char waste[1000];
	while(fscanf(read2,"%s",email)==1)
	{
		if(strcmp(email,a.email)==0)
		{
			printf("Email Address Already exists, Try again\n");
			fclose(read2);
			goto lbl2;
		}
		fscanf(read2,"%s %s %s %s",waste,waste,waste,waste);
	}

	fp = fopen("profile_admin.txt","a");
	fprintf(fp,"%s %s\n",a.email,a.pwd);
	printf("Registered Succesfully!!\n");
	fclose(fp);
	fclose(read);
	fclose(read2);
}
void reg()
{
	int ch;
	lbl1:printf("Register As a\t1. Student\t2. Administrator");
	printf("\nTo go back, press 999\nTo Go back to main menu, press 9999\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
		reg_stud();
		break;
		case 2:
		reg_admin();
		break;
		case 999:
		return;
		case 9999:
		main();
		default:
		printf("Wrong input, Select again\n");
		goto lbl1;
	}
}
int login_stud()
{
	int n=0,i;
	stud a,data[1000];
	printf("Enter email address\n");
	scanf("%s",a.email);
	printf("Enter your password\n");
	scanf("%s",a.pwd);
	FILE *read;	
	read = fopen("profile_stud.txt","r");
	char email[1000];
	while(fscanf(read,"%s",email)==1)
	{
		strcpy(data[n].email,email);
		fscanf(read,"%s %s %s %s",data[n].pwd,data[n].name,data[n].contact,data[n].roll);
		n++;
	}
	for(i=0;i<n;i++)
	{
		//printf("%d\n",strcmp(data[i].email,a.email));
		if(strcmp(data[i].email,a.email)==0 && strcmp(data[i].pwd,a.pwd)==0)
		{
			//printf("Email Address Already exists, Try again\n");
			fclose(read);
			return i;
		}
	}
	return -1;
}
int login_admin()
{
	int n=0,i;
	admin a,data[1000];
	printf("Enter email address\n");
	scanf("%s",a.email);
	printf("Enter your password\n");
	scanf("%s",a.pwd);
	FILE *read;
	read = fopen("profile_admin.txt","r");
	char email[1000];
	while(fscanf(read,"%s",email)==1)
	{
		strcpy(data[n].email,email);
		fscanf(read,"%s",data[n].pwd);
		n++;
	}
	for(i=0;i<n;i++)
	{
		//printf("%d\n",strcmp(data[i].email,a.email));
		if(strcmp(data[i].email,a.email)==0 && strcmp(data[i].pwd,a.pwd)==0)
		{
			//printf("Email Address Already exists, Try again\n");
			fclose(read);
			return i;
		}
	}
	return -1;
}
void opensubadmin(int nbr)
{
	//printf("ss\n");
	char fnameq[20],fnamea[20],fnames[20];
	sprintf(fnameq,"sub_%d_q.txt",nbr);
	sprintf(fnamea,"sub_%d_a.txt",nbr);
	sprintf(fnames,"sub_%d_s.txt",nbr);
	printf("%s %s %s\n",fnameq,fnamea,fnames);
	int ch=-1,ch2,ch3,j;
	while(1)
	{
		FILE *readq,*reada,*reads;
		//printf("Yo 1\n");
		readq = fopen(fnameq,"r");
		//printf("Yo 2\n");
		reada = fopen(fnamea,"r");
		//printf("Yo 3\n");
		reads = fopen(fnames,"r");
		//printf("Yo 4\n");
		qa data[50];
		int n=0,i;
		
		while(fgets(data[n].q,9995,readq))
		{
			//fscanf(readq,"%s%s%s%s",data[n].oa,data[n].ob,data[n].oc,data[n].od);
			fgets(data[n].oa,99,readq);
			fgets(data[n].ob,99,readq);
			fgets(data[n].oc,99,readq);
			fgets(data[n].od,99,readq);
			fscanf(reada,"%s",data[n].a);
			n++;
		}
		printf("1. View all questions\t2. Insert New Question\t3. Delete a question\t4. Modify a Question\t5. View Stats\t0. Go back\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				fclose(readq);
				fclose(reada);
				fclose(reads);
				return;
			case 1:
				printf("==============================================\n");
				for(i=0;i<n;i++)
				{
					printf("Q%d. %sa) %sb) %sc) %sd) %sA%d. %s\n",i+1,data[i].q,data[i].oa,data[i].ob,data[i].oc,data[i].od,i+1,data[i].a);
				}
				printf("==============================================\n");
				fclose(readq);
				fclose(reada);
				fclose(reads);
				break;
			case 2:
				char ques[10000],opa[100],opb[100],opc[100],opd[100];
				char ans[10];
				printf("Enter the question:\n");
				getchar();
				gets(ques);
				printf("Enter Option a)\n");
				gets(opa);
				printf("Enter Option b)\n");
				gets(opb);
				printf("Enter Option c)\n");
				gets(opc);
				printf("Enter Option d)\n");
				gets(opd);
				printf("Enter the answer:\n");
				scanf("%s",ans);
				FILE *fpq,*fpa;
				fpq = fopen(fnameq,"a");
				fpa = fopen(fnamea,"a");
				fprintf(fpq,"%s\n%s\n%s\n%s\n%s\n",ques,opa,opb,opc,opd);
				fprintf(fpa,"%s\n",ans);
				printf("Question Inserted Successfully\n");
				fclose(readq);
				fclose(reada);
				fclose(reads);
				fclose(fpq);
				fclose(fpa);
				break;
			case 3:
				lbl6:printf("Enter the Question number you want to delete\nPress -1 to go back\n");
				
				scanf("%d",&ch2);
				if(ch2==-1)
				{
					fclose(readq);
					fclose(reada);
					fclose(reads);
					break;
				}
				else
				{
					if(ch2>=1 && ch2<=n)
					{
						printf("Q%d. %sa) %sb) %sc) %sd) %sA%d. %s\n",ch2,data[ch2-1].q,data[ch2-1].oa,data[ch2-1].ob,data[ch2-1].oc,data[ch2-1].od,ch2,data[ch2-1].a);
						printf("Are you sure to delete this ques?\t1. Yes\t2. No\n");
						
						scanf("%d",&ch3);
						if(ch3!=1)
						{
							goto lbl6;
						}
						else
						{
							fclose(readq);
							fclose(reada);
							fclose(reads);
							FILE *fpq,*fpa;
							fpq = fopen(fnameq,"w");
							fpa = fopen(fnamea,"w");
							for(i=0;i<n;i++)
							{
								if(i==ch2-1)
									continue;
								fprintf(fpq,"%s%s%s%s%s",data[i].q,data[i].oa,data[i].ob,data[i].oc,data[i].od);
								fprintf(fpa,"%s\n",data[i].a);
							}
							fclose(fpq);
							fclose(fpa);
							printf("Question Deleted Successfully\n");
							break;
						}

					}
					else
					{
						printf("Invalid Input\n");
						fclose(readq);
						fclose(reada);
						fclose(reads);
						break;
					}
				}
			case 4:
				lbl7:printf("Enter the Question number you want to Modify\nPress -1 to go back\n");
				scanf("%d",&ch2);
				if(ch2==-1)
				{
					fclose(readq);
					fclose(reada);
					fclose(reads);
					break;
				}
				else
				{
					if(ch2>=1 && ch2<=n)
					{
						printf("Original Question:\n");
						printf("Q%d. %sa) %sb) %sc) %sd) %sA%d. %s\n",ch2,data[ch2-1].q,data[ch2-1].oa,data[ch2-1].ob,data[ch2-1].oc,data[ch2-1].od,ch2,data[ch2-1].a);
						printf("Are you sure to modify this ques?\t1. Yes\t2. No\n");
						
						scanf("%d",&ch3);
						if(ch3!=1)
						{
							goto lbl7;
						}
						else
						{
							fclose(readq);
							fclose(reada);
							fclose(reads);
							printf("Enter the question:\n");
							getchar();
							gets(data[ch2-1].q);
							printf("Enter Option a)\n");
							gets(data[ch2-1].oa);
							printf("Enter Option b)\n");
							gets(data[ch2-1].ob);
							printf("Enter Option c)\n");
							gets(data[ch2-1].oc);
							printf("Enter Option d)\n");
							gets(data[ch2-1].od);
							printf("Enter the answer:\n");
							scanf("%s",data[ch2-1].a);

							FILE *fpq,*fpa;
							fpq = fopen(fnameq,"w");
							fpa = fopen(fnamea,"w");
							for(i=0;i<n;i++)
							{
								if(i==ch2-1)
									fprintf(fpq,"%s\n%s\n%s\n%s\n%s\n",data[i].q,data[i].oa,data[i].ob,data[i].oc,data[i].od);
								else
									fprintf(fpq,"%s%s%s%s%s",data[i].q,data[i].oa,data[i].ob,data[i].oc,data[i].od);
								fprintf(fpa,"%s\n",data[i].a);
							}
							fclose(fpq);
							fclose(fpa);
							printf("Question Deleted Successfully\n");
							break;
						}

					}
					else
					{
						printf("Invalid Input\n");
						fclose(readq);
						fclose(reada);
						fclose(reads);
						break;
					}
				}
			case 5:
				stat statdata[100];
				j=0;
				while(fscanf(reads,"%s",statdata[j].roll)==1)
				{
					fscanf(reads,"%f%f",&(statdata[j].mo),&(statdata[j].tm));
					j++;
				}

				quickSort(statdata,0,j-1);
				fclose(readq);
				fclose(reada);
				fclose(reads);
				FILE *fp;
				//fp = fopen(fnames,"w");
				printf("Roll No\t\tMarks Obtained\tTotal Marks\tPercentage\n");
				for(int i=j-1;i>=0;i--)
				{
					printf("%s\t\t%f\t%f\t%f\n",statdata[i].roll,statdata[i].mo,statdata[i].tm,(statdata[i].mo/statdata[i].tm)*100.0);
				}
				//fclose(fp);
				break;
			default:
				printf("Invalid Input\n");
				fclose(readq);
				fclose(reada);
				fclose(reads);
		}
	}
	
}
void print_profile_data(stud a)
{
	printf("Name - %s\tEmail - %s\nRoll No. - %s\tContact - %s\n",a.name,a.email,a.roll,a.contact);
}
void givetest(int nbr,int sidx)
{
	FILE *readq,*reada;
	char fnameq[20];
	char fnamea[20];
	sprintf(fnameq,"sub_%d_q.txt",nbr);
	sprintf(fnamea,"sub_%d_a.txt",nbr);
	readq=fopen(fnameq,"r");
	reada=fopen(fnamea,"r");
	int n=0,i;
	qa data[100];
	while(fgets(data[n].q,9995,readq))
	{
		//fscanf(readq,"%s%s%s%s",data[n].oa,data[n].ob,data[n].oc,data[n].od);
		fgets(data[n].oa,99,readq);
		fgets(data[n].ob,99,readq);
		fgets(data[n].oc,99,readq);
		fgets(data[n].od,99,readq);
		fscanf(reada,"%s",data[n].a);
		n++;
	}
	printf("No. of Questions - %d, Time Limit 10 mins.\n1. Start Test\t0.Go back\n",n);
	int ch;
	scanf("%d",&ch);
	fclose(readq);
	fclose(reada);
	if(ch!=1)
	{
		return;
	}
	int submitted=0;
	int arr[n];
	for(i=0;i<n;i++)
		arr[i]=0;
	char ans[n][10];
	struct timeval t0,t1;
	gettimeofday(&t0,NULL);
	//clock_t t0 = clock();
	while(submitted<n && ((double)(t1.tv_sec-t0.tv_sec))<=600)
	{
		for(i=0;i<n;i++)
		{
			if(!arr[i])
			{
				printf("Q %d) %sa) %sb) %sc) %sd) %s",i+1,data[i].q,data[i].oa,data[i].ob,data[i].oc,data[i].od);
				printf("Give answer:\n");
				//char tempans[10];
				scanf("%s",ans[i]);
				//strcpy()
				lbl8:printf("1. Save\t2.Submit\t3. Time Remaining\tDefault is Save\n");
				int ch2;
				scanf("%d",&ch2);
				{
					if(ch2==2)
					{
						arr[i]=1;
						submitted++;
					}
					else if(ch2==3)
					{
						gettimeofday(&t1,NULL);
						printf("Remaining Time in seconds = %lf\n",600.0-((double)(t1.tv_sec-t0.tv_sec)));
						goto lbl8;
					}

				}
			}
		}
		gettimeofday(&t1,NULL);
	}

	int correct=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(ans[i],data[i].a)==0)
		{
			correct++;
		}
	}
	printf("Your score is %d out of %d\n",correct,n);
	FILE *readstud;
	readstud = fopen("profile_stud.txt","r");
	int nstud=0;
	stud studdata[100];
	while(fscanf(readstud,"%s",studdata[nstud].email)==1)
	{
		//strcpy(data[n].email,email);
		fscanf(readstud,"%s %s %s %s",studdata[nstud].pwd,studdata[nstud].name,studdata[nstud].contact,studdata[nstud].roll);
		nstud++;
	}
	FILE *fp;
	char fnames[20];
	sprintf(fnames,"sub_%d_s.txt",nbr);
	fp = fopen(fnames,"a");
	fprintf(fp,"%s %f %f\n",studdata[sidx].roll,(float)correct,(float)n);
	fclose(fp);

}
void opensubstud(int nbr,int sidx)
{
	int ch,j;
	char fnames[20];
	sprintf(fnames,"sub_%d_s.txt",nbr);
	while(1)
	{
		printf("1. View Stats\t2. Give a Test\t0. Go Back\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				return;
			case 1:
				FILE *reads;
				reads = fopen(fnames,"r");
				stat statdata[100];
				j=0;
				while(fscanf(reads,"%s",statdata[j].roll)==1)
				{
					fscanf(reads,"%f%f",&(statdata[j].mo),&(statdata[j].tm));
					j++;
				}

				quickSort(statdata,0,j-1);
				fclose(reads);
				//FILE *fp;
				//fp = fopen(fnames,"w");
				printf("Roll No\t\tMarks Obtained\tTotal Marks\tPercentage\n");
				for(int i=j-1;i>=0;i--)
				{
					printf("%s\t\t%f\t%f\t%f\n",statdata[i].roll,statdata[i].mo,statdata[i].tm,(statdata[i].mo/statdata[i].tm)*100.0);
				}
				//fclose(fp);
				break;
			case 2:
				givetest(nbr,sidx);
				break;
			default:
				printf("Invalid Input\n");
		}
	}
	
}
void session_stud(int idx)
{
	int ch=-1,n=0,i,ch2;
	int code;
	FILE *read;	
	read = fopen("profile_stud.txt","r");
	char email[1000];
	stud data[100];
	while(fscanf(read,"%s",email)==1)
	{
		strcpy(data[n].email,email);
		fscanf(read,"%s %s %s %s",data[n].pwd,data[n].name,data[n].contact,data[n].roll);
		n++;
	}
	fclose(read);
	stud a;
	a=data[idx];
	/*a.email = data[idx].email;
	a.pwd = data[idx].pwd;
	a.name = data[idx].name;
	a.contact = data[idx].contact;
	a.roll = data[idx].roll;*/
	while(1)
	{
		printf("1. Profile Information\t2. View all Subjects\t0. Logout\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				//fcloses
				return;
			case 1:
				print_profile_data(a);
				break;
			case 2:
				FILE *read_sub;
				read_sub = fopen("subjects.txt","r");
				subjects subdata[1000];
				n=0;
				while(fscanf(read_sub,"%d",&code)==1)
				{
					//strcpy(data[n].email,email);
					subdata[n].code=code;
					fscanf(read_sub,"%s",subdata[n].sub);
					n++;
				}

				printf("Code\tSubject Name\n");
				printf("==============================================\n");
				for(i=0;i<n;i++)
				{
					printf("%d\t%s\n",subdata[i].code,subdata[i].sub);
				}
				printf("==============================================\n");
				printf("Select a subject code.\nSelect -1 to go back\n");
				scanf("%d",&ch2);
				if(ch2==-1)
				{
					fclose(read_sub);
					break;
				}
				else
				{
					if(ch2>=1 && ch2<=n)
					{
						fclose(read_sub);
						opensubstud(ch2,idx);
					}
					else
					{
						printf("Invalid Code, Select Again\n");
						fclose(read_sub);
						break;
					}
				}
				//fclose(read_sub);
				break;
			default:
				printf("Invalid Input\n");
				//fcloses
		}

	}

}
void session_admin(int idx)
{
	int ch=-1,n,i,ch2;
	int code;
	char newsubname[1000];
	while(1)
	{
		FILE *read;
		read = fopen("subjects.txt","r");
		subjects data[1000];
		n=0;
		while(fscanf(read,"%d",&code)==1)
		{
			//strcpy(data[n].email,email);
			data[n].code=code;
			fscanf(read,"%s",data[n].sub);
			n++;
		}
		printf("1. View all subjects\t2. Create a new Subject\t0. Log Out\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 0:
				fclose(read);
				return;
			case 1:
				printf("Code\tSubject Name\n");
				printf("==============================================\n");
				for(i=0;i<n;i++)
				{
					printf("%d\t%s\n",data[i].code,data[i].sub);
				}
				printf("==============================================\n");
				printf("Select a subject code to modify it.\nSelect -1 to go back\n");
				scanf("%d",&ch2);
				if(ch2==-1)
				{
					fclose(read);
					break;
				}
				else
				{
					if(ch2>=1 && ch2<=n)
					{
						fclose(read);
						opensubadmin(ch2);
					}
					else
					{
						printf("Invalid Code, Select Again\n");
						fclose(read);
						break;
					}
				}
				//fclose(read);
				break;
			case 2:
				lbl5:printf("Enter Subject name\n");
				scanf("%s",newsubname);
				for(i=0;i<n;i++)
				{
					if(strcmp(newsubname,data[i].sub)==0)
					{
						printf("Subject Name already exists\n");
						goto lbl5;
					}
				}
				FILE *fp;
				fp = fopen("subjects.txt","a");
				fprintf(fp,"%d %s",n+1,newsubname);
				fclose(fp);
				fclose(read);
				FILE *fp2;
				char fname[20];
				sprintf(fname,"sub_%d_q.txt",n+1);
				fp2 = fopen(fname,"a");
				fclose(fp2);
				sprintf(fname,"sub_%d_a.txt",n+1);
				fp2 = fopen(fname,"a");
				fclose(fp2);
				sprintf(fname,"sub_%d_s.txt",n+1);
				fp2 = fopen(fname,"a");
				fclose(fp2);
				printf("Subject registered successfully with id %d\n",n+1);
				break;
			default:
				printf("Invalid Input\n");
				fclose(read);
		}
	}
	
}
void login()
{
	int ch,idx;
	lbl4:printf("Login As a\t1. Student\t2. Administrator");
	printf("\nTo go back, press 999\n");
	scanf("%d",&ch);
	switch(ch){
		case 1:
		idx = login_stud();
		if(idx==-1)
		{
			printf("Username or password Incorrect\n");
			goto lbl4;
		}
		session_stud(idx);
		break;
		case 2:
		idx=login_admin();
		//printf("idx->%d\n",idx);
		if(idx==-1)
		{
			printf("Username or password Incorrect\n");
			goto lbl4;
		}
		session_admin(idx);
		break;
		case 999:
		return;
		default:
		printf("Wrong input, Select again\n");
		goto lbl4;
	}
}

int main()
{
	int ch=-1;
	while(ch!=3)
	{
		printf("Choose:\n1. Login\t2. Register\t3. Quit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			login();
			break;
			case 2:
			reg();
			break;
			case 3:
			exit(-1);
			default:
			printf("Wrong input, Select again\n");
			//goto x;
		}
	}
	
}