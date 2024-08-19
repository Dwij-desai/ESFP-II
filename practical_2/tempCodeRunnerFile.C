int deleteChoice;
    printf("Enter student id or name to delete: ");
    scanf("%d", &deleteChoice);

    int index = searchRecord(students, *num_records, 1, deleteChoice,""); 

    if (index != -1) {
        for (int j = index; j < (*num_records - 1); j++) {
            students[j] = students[j + 1];
        }

        (*num_records)--;
        students = (struct Student *)realloc(students, (*num_records) * sizeof(struct Student));

        printf("Record deleted successfully\n");
    } else {
        printf("Record not found.\n");
    }