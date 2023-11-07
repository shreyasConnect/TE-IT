#!/bin/bash



# Function to create a new address book file named "addressbook1.txt"

create() {

	# Define the file name

	file_name="addressbook"



	# Create the file

	touch "$file_name"



	# Check if the file exists

	if [ -e "$file_name" ]; then

	    echo "File '$file_name' exists."

	else

	    echo "File '$file_name' does not exist."

	fi

}





# Function to display the contents of the address book file

display() {

    cat addressbook.txt

    echo

}



# Function to insert a new record into the address book file

insert() {

    while true; do

        read -p "Enter your roll number: " roll

        # Validate phone is numeric

        if ! [[ "$roll" =~ ^[0-9]{5}$ ]]; then

            echo "Invalid roll number. Please enter a valid numeric value with 5 digits."

        else

            break

        fi

    done

    while true; do

        read -p "Enter your name: " name

        # Validate name does not contain special characters

        if [[ "$name" =~ [^a-zA-Z[:space:]] ]]; then

            echo "Invalid name. Name should only contain letters,and spaces."

        else

            break

        fi

    done

    while true; do

        read -p "Enter your phone number: " phone

        # Validate phone is numeric

        if ! [[ "$phone" =~ ^[0-9]{10}$ ]]; then

            echo "Invalid phone number. Please enter a valid numeric value with 10 digits."

        else

            break

        fi

    done

    while true; do

        read -p "Enter your city: " city

        # Validate city does not contain special characters

        if [[ "$city" =~ [^a-zA-Z0-9[:space:]] ]]; then

            echo "Invalid city. City should only contain letters, numbers, and spaces."

        else

            break

        fi

    done

    while true; do

        read -p "Enter your pincode: " pincode

        # Validate pincode is numeric

        if ! [[ "$pincode" =~ ^[0-9]{6}$ ]]; then

            echo "Invalid pincode. Please enter a valid numeric value with 6 digits."

        else

            break

        fi

    done

    echo "$roll $name $phone $city $pincode" >> addressbook.txt

    echo "Inserted Successfully"

}



# Function to delete a record from the address book file by ID

delete() {

    read -p "Enter the roll number which you want to delete: " roll

    # Check if the record with the specified ID exists

    if ! grep -q "^$roll\s" addressbook.txt; then

        echo "Record with roll number $roll not found."

        return

    fi

    # Create a temporary file without the record to be deleted, then replace the original file

    grep -v "^$roll\s" addressbook.txt > temp.txt

    mv temp.txt addressbook.txt

    echo "Record Delete Successfully"

    echo

}



# Function to modify a record in the address book file by ID

modify() {

    read -p "Enter the roll number you want to Modify" roll

    # Check if the record with the specified ID exists

    if ! grep -q "^$roll\s" addressbook.txt; then

        echo "Record with roll number $roll not found."

        return

    fi

    read -p "Enter your new name: " name

    read -p "Enter your phone number: " phone

    read -p "Enter your city: " city

    read -p "Enter your picnode: " pincode

    # Use 'sed' command to replace the line containing the old record with the new record

    sed -i "/^$roll\s/c$roll\t$name\t$phone\t$city\t$pincode" addressbook.txt

    echo "Modified Successfully"

    echo

}



# Function to display the menu options

menu() {

    echo " 1. Create   "

    echo " 2. Display  "

    echo " 3. Insert   "

    echo " 4. Delete   "

    echo " 5. Modify   "

    echo " 6. Exit     "



}



while true; do

    menu

    read -p "Enter your choice: " choice

    echo

    # Validate user's choice is a numeric value between 1 and 7

    if ! [[ "$choice" =~ ^[1-6]$ ]]; then

        echo "Invalid Choice. Please enter a numeric value between 1 and 6."

        continue

    fi

    # Process the user's choice using a case statement

    case $choice in

        1) create ;; # Call the create function

        2) display ;; # Call the display function

        3) insert ;; # Call the insert function

        4) delete ;; # Call the delete function

        5) modify ;; # Call the modify function

        6) exit 0 ;;

    esac

    # Exit the script with status code 0

    echo

done

