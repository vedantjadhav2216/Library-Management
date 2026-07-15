#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_login(char user[20], char pass[20], char file[20])
{
    FILE *fp;
    fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("\n\t File Open Error");
    }
    else
    {
        char user1[20], pass1[20];
        fscanf(fp, "%s%s", user1, pass1);
        fclose(fp);
        if (strcmp(user, user1) == 0 && strcmp(pass, pass1) == 0)
        {
            return 1;
        }
    }
    return 0;
}
struct book
{
    int id;
    char name[20], author[20], publication[20];
    int qty, cost;
    float total;
};
void add()
{
    struct book B;
    FILE *fp;
    fp = fopen("bookrecord.txt", "a");
    if (fp == NULL)
    {
        printf("\n\t bookrecord.txt File Open Error in add function");
    }
    else
    {
        printf("\n\t Enter the Book Id:");
        scanf("%d", &B.id);
        printf("\n\t Enter the Book Name:");
        scanf("%s", &B.name);
        printf("\n\t Enter the Book Author Name:");
        scanf("%s", B.author);
        printf("\n\t Enter the Book Publication:");
        scanf("%s", B.publication);
        printf("\n\t Enter the Book Quantity:");
        scanf("%d", &B.qty);
        printf("\n\t Enter the Book Cost:");
        scanf("%d", &B.cost);
        B.total = B.cost * B.qty;
        fprintf(fp, "\n\t%d %s %s %s %d %d %f", B.id, B.name, B.author, B.publication, B.qty, B.cost, B.total);
        fclose(fp);
    }
}
void display()
{
    struct book B;
    FILE *fp;
    int count = 0;
    fp = fopen("bookrecord.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t bookrecord.txt File Open Error in display function");
    }
    else
    {
        printf("\n\t ..........................................");
        printf("\n\t Id Name Author publication Qunatity Cost Total");
        printf("\n\t ..........................................");
        while (fscanf(fp, "\n\t%d %s %s %s %d %d %f", &B.id, B.name, B.author, B.publication, &B.qty, &B.cost, &B.total) != EOF)
        {
            count++;
            printf("\n\t%d %s %s %s %d %d %f", B.id, B.name, B.author, B.publication, B.qty, B.cost, B.total);
        }
        fclose(fp);
        printf("\n\t ..........................");
        printf("\n\t Total:%d", count);
        printf("\n\t ..........................");
    }
}
void search(int id)
{
    struct book B;
    FILE *fp;
    int count = 0;
    fp = fopen("bookrecord.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t bookrecord.txt File Open Error in search function");
    }
    else
    {
        printf("\n\t ..........................................");
        printf("\n\t Id Name Author publication Qunatity Cost Total");
        printf("\n\t ..........................................");
        while (fscanf(fp, "\n\t%d %s %s %s %d %d %f", &B.id, B.name, B.author, B.publication, &B.qty, &B.cost, &B.total) != EOF)
        {
            if (B.id == id)
            {
                count++;
                printf("\n\t%d %s %s %s %d %d %f", B.id, B.name, B.author, B.publication, B.qty, B.cost, B.total);
            }
        }
        fclose(fp);
        if (count == 0)
        {
            printf("\n\t Record Not Found");
        }
        else
        {
            printf("\n\t ..........................");
            printf("\n\t Record Found %d times", count);
            printf("\n\t ..........................");
        }
    }
}
void delete(int id)
{
    struct book B;
    FILE *fp, *fp1;
    int count = 0;
    fp = fopen("bookrecord.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t bookrecord.txt File Open Error in delete function");
    }
    else
    {
        fp1 = fopen("tmp.txt", "w");
        while (fscanf(fp, "\n\t%d %s %s %s %d %d %f", &B.id, B.name, B.author, B.publication, &B.qty, &B.cost, &B.total) != EOF)
        {
            if (B.id == id)
            {
                count++;
            }
            else
            {
                fprintf(fp1, "\n\t%d %s %s %s %d %d %f",
                        B.id, B.name, B.author, B.publication, B.qty, B.cost, B.total);
            }
        }
        fclose(fp);
        fclose(fp1);
        remove("bookrecord.txt");
        rename("tmp.txt", "bookrecord.txt");
        if (count == 0)
        {
            printf("\n\t Record Not Found");
        }
        else
        {
            printf("\n\t ..........................");
            printf("\n\t Record Found %d times", count);
            printf("\n\t ..........................");
        }
    }
}
void update(int id)
{
    struct book B;
    FILE *fp, *fp1;
    int count = 0;
    fp = fopen("bookrecord.txt", "r");
    if (fp == NULL)
    {
        printf("\n\t book.txt File Open Error in update function");
    }
    else
    {
        fp1 = fopen("tmp.txt", "w");
        while (fscanf(fp, "\n\t%d %s %s %s %d %d %f", &B.id, B.name, B.author, B.publication, &B.qty, &B.cost, &B.total) != EOF)
        {
            if (B.id == id)
            {
                count++;
                printf("\n\t Enter the Book Name:");
                scanf("%s", B.name);
                printf("\n\t Enter the Book Author Name:");
                scanf("%s", B.author);
                printf("\n\t Enter the Book Publication:");
                scanf("%s", B.publication);
                printf("\n\t Enter the Book Quantity:");
                scanf("%d", &B.qty);
                printf("\n\t Enter the Book Cost:");
                scanf("%d", &B.cost);
                B.total = B.cost * B.qty;
                fprintf(fp1, "\n\t%d %s %s %s %d %d %f", B.id, B.name, B.author, B.publication, B.qty, B.cost, B.total);
            }
            else
            {
                fprintf(fp1, "\n\t%d %s %s %s %d %d %f", B.id, B.name, B.author, B.publication, B.qty, B.cost, B.total);
            }
        }
        fclose(fp);
        fclose(fp1);
        remove("bookrecord.txt");
        rename("tmp.txt", "bookrecord.txt");
        if (count == 0)
        {
            printf("\n\t Record Not Found");
        }
        else
        {
            printf("\n\t ..........................");
            printf("\n\t Record Found %d times", count);
            printf("\n\t ..........................");
        }
    }
}
int main()
{
    char ch, user[20], pass[20];
    int choice, x, id;
    do
    {
        system("cls");
        printf("\n\t .........................................................");
        printf("\n\t Login Section");
        printf("\n\t .........................................................");
        printf("\n\t 1.Admin Login");
        printf("\n\t 2.Customer Login");
        printf("\n\t 3.Exit");
        printf("\n\t Enter Your Choice(1-3):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n\t Enter User Name:");
            scanf("%s", &user);
            printf("\n\t Enter User Password:");
            scanf("%s", &pass);
            x = check_login(user, pass, "admin.txt");
            if (x == 1)
            {
                do
                {
                    system("cls");
                    printf("\n\t .........................................................");
                    printf("\n\t Admin Section");
                    printf("\n\t .........................................................");
                    printf("\n\t 1.Add Record");
                    printf("\n\t 2.Display Record");
                    printf("\n\t 3.Search Record");
                    printf("\n\t 4.Delete Record");
                    printf("\n\t 5.Update Record");
                    printf("\n\t 6.Logout");
                    printf("\n\t Enter Your Choice(1-6):");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        add();
                        break;

                    case 2:
                        display();
                        break;

                    case 3:
                        printf("\n\t Enter Id To Search the Record:");
                        scanf("%d", &id);
                        search(id);
                        break;

                    case 4:
                        printf("\n\t Enter Id To Delete the Record:");
                        scanf("%d", &id);
                        delete(id);
                        break;

                    case 5:
                        printf("\n\t Enter Id To Update the Record:");
                        scanf("%d", &id);
                        update(id);
                        break;

                    case 6:
                        exit(0);
                        break;

                    default:
                        printf("\n\t Invalid Admin Choice");
                        break;
                    }
                    printf("\n\t Do You Want To Continue In Admin Section(y/n):");
                    scanf("%s", &ch);
                } while (ch == 'Y' || ch == 'y');
            }
            else
            {
                printf("\n\t Invalid Admin User");
            }
            break;

        case 2:
            printf("\n\t Enter User Name:");
            scanf("%s", &user);
            printf("\n\t Enter User Password:");
            scanf("%s", &pass);
            x = check_login(user, pass, "user.txt");
            if (x == 1)
            {
                do
                {
                    system("cls");
                    printf("\n\t .........................................................");
                    printf("\n\t Customer Section");
                    printf("\n\t .........................................................");
                    printf("\n\t 1.Display Record");
                    printf("\n\t 2.Search Record");
                    printf("\n\t 3.Logout");
                    printf("\n\t Enter Your Choice(1-3):");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        display();
                        break;

                    case 2:
                        printf("\n\t Enter Id To Search the Record:");
                        scanf("%d", &id);
                        search(id);
                        break;

                    case 3:
                        exit(0);
                        break;

                    default:
                        printf("\n\t Invalid Admin Choice");
                        break;
                    }
                    printf("\n\t Do You Want To Continue In Customer Section(y/n):");
                    scanf("%s", &ch);
                } while (ch == 'Y' || ch == 'y');
            }
            else
            {
                printf("\n\t Invalid Customer User");
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\n\t Invalid Login Choice");
            break;
        }
        printf("\n\t Do You Want To Continue In Login Section(y/n):");
        scanf("%s", &ch);
    } while (ch == 'Y' || ch == 'y');
    return 0;
}