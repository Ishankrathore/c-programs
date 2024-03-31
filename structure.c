#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct customer { char customer_name[50]; char mobile_no[20]; int room_no; char room_type[10]; float per_day_room_charge; char check_in_date[20]; char check_out_date[20]; };
int total_days; float total_bill; void print_bill(struct customer c);

int date_diff(int d1, int m1, int y1, int d2, int m2, int y2);

int main() {

struct customer c1;

printf("Enter Customer Name: "); 
// Check if fgets returns NULL
if (fgets(c1.customer_name, 50, stdin) == NULL) {
    printf("Error reading customer name\n");
    return 1;
}
// Remove trailing newline character
c1.customer_name[strcspn(c1.customer_name, "\n")] = '\0';

printf("Enter Mobile No: "); 
// Check if fgets returns NULL
if (fgets(c1.mobile_no, 20, stdin) == NULL) {
    printf("Error reading mobile number\n");
    return 1;
}
// Remove trailing newline character
c1.mobile_no[strcspn(c1.mobile_no, "\n")] = '\0';

printf("Enter Room No: "); 
scanf("%d", &c1.room_no);

printf("Enter Room Type (AC/Non-AC): "); 
// Use a loop to validate the input
while (1) {
    scanf("%s", c1.room_type);
    // Check if the input is either AC or Non-AC
    if (strcmp(c1.room_type, "AC") == 0 || strcmp(c1.room_type, "Non-AC") == 0) {
        break;
    }
    else {
        printf("Invalid room type. Please enter AC or Non-AC\n");
    }
}

printf("Enter per day room charge: "); 
// Use a loop to validate the input
while (1) {
    scanf("%f", &c1.per_day_room_charge);
    // Check if the input is positive
    if (c1.per_day_room_charge > 0) {
        break;
    }
    else {
        printf("Invalid room charge. Please enter a positive value\n");
    }
}

printf("\nEnter check-in date (DD/MM/YYYY): "); 
// Parse the check-in date
int check_in_day, check_in_month, check_in_year; 
// Use a loop to validate the input
while (1) {
    scanf("%s", c1.check_in_date);
    // Check if the input format is correct
    if (sscanf(c1.check_in_date, "%d/%d/%d", &check_in_day , &check_in_month, &check_in_year) == 3) {
        break;
    }
    else {
        printf("Invalid check-in date format. Please enter DD/MM/YYYY\n");
    }
}

printf("\nEnter check-out date (DD/MM/YYYY): "); 
// Parse the check-out date
int check_out_day, check_out_month, check_out_year; 
// Use a loop to validate the input
while (1) {
    scanf("%s", c1.check_out_date);
    // Check if the input format is correct
    if (sscanf(c1.check_out_date, "%d/%d/%d", &check_out_day,&check_out_month, &check_out_year) == 3) {
        break;
    }
    else {
        printf("Invalid check-out date format. Please enter DD/MM/YYYY\n");
    }
}

// Calculate the total days of stay
total_days = date_diff(check_in_day, check_in_month, check_in_year,
                           check_out_day, check_out_month, check_out_year);

if (total_days < 0) {
    printf("Invalid date range\n");
    return 1;
}

// Calculate the total bill amount
total_bill = c1.per_day_room_charge * total_days;

// Print the bill by calling the function
print_bill(c1);

return 0; 
}

 void print_bill(struct customer c) {
printf("\n--------- Hotel Grand Mark Bill ---------\n");

printf("Customer Name: %s\n", c.customer_name); 
printf("Mobile No: %s\n", c.mobile_no);

printf("Room No: %d\n", c.room_no); 
printf("Room Type: %s\n", c.room_type);

printf("Per day room charge: %.2f\n", c.per_day_room_charge);

printf("Check-in Date: %s\n", c.check_in_date);

printf("Check-out Date: %s\n",c.check_out_date);

printf("Total days of stay: %d\n", total_days);

printf("Total Bill: %.2f\n", total_bill);

printf("-----------------------------------------\n");
}

 int date_diff(int d1, int m1, int y1, int d2, int m2, int y2) { if (d1 < 1 || d1 > 31 || d2 < 1 || d2 > 31 || m1 < 1 || m1 > 12 || m2 < 1 || m2 > 12 || y1 < 0 || y2 < 0) { return -1; }

// Check for leap years
int is_leap_1 = (y1 % 4 == 0 && y1 % 100 != 0) || (y1 % 400 == 0);
int is_leap_2 = (y2 % 4 == 0 && y2 % 100 != 0) || (y2 % 400 == 0);

// Check for valid days in February
if ((m1 == 2 && d1 > (is_leap_1 ? 29 : 28)) ||
    (m2 == 2 && d2 > (is_leap_2 ? 29 : 28))) {
    return -1;
}

// Check for valid days in other months
int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
if (d1 > days_in_month[m1 - 1] || d2 > days_in_month[m2 - 1]) {
    return -1;
}

// Convert dates to number of days since Jan 01, year 0
long n1 = y1 * 365 + d1;
long n2 = y2 * 365 + d2;

// Add extra days for leap years
for (int i = 0; i < y1; i++) {
    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
        n1++;
    }
}

for (int i = 0; i < y2; i++) {
    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
        n2++;
    }
}

// Add extra days for months
for (int i = 0; i < m1 - 1; i++) {
    n1 += days_in_month[i];
}

for (int i = 0; i < m2 - 1; i++) {
    n2 += days_in_month[i];
}

// Return the difference between the two dates
return n2 - n1;
}



