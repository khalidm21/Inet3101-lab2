# Parts Inventory Manager

## Overview
This project is a Parts Inventory Manager written in C. It allows you to add, delete, and print part records in an inventory database. Each part has a unique number, name, size, size metric, and cost.

## Features
- **Add Records**: Add new part records to the database.
- **Delete Records**: Delete the last added part record.
- **Print Records**: Print all part records currently in the database.
- **Total Records**: Print the total number of part records.
- **Database Size**: Print the current size of the database in memory.
- **Change Log**: Print the total number of changes made to the database (additions and deletions).

## Code Summary

### Structure Declaration
The `Part` structure holds information about a part in the inventory. Fields include:

- `partNumber`: The unique number assigned to the part.
- `partName`: The name of the part.
- `partSize`: The size of the part.
- `partSizeMetric`: The metric unit of the part size (e.g., pounds, kilograms, feet).
- `partCost`: The cost of the part.

### Functions

#### `printRecords`
**Purpose**: Prints all part records currently in the database.

**Parameters**:
- `Part *parts`: Pointer to the array of parts.
- `int count`: The number of parts in the database.

#### `addRecord`
**Purpose**: Adds a new record to the database.

**Parameters**:
- `Part **parts`: Double pointer to the array of parts.
- `int *count`: Pointer to the count of parts.

#### `deleteRecord`
**Purpose**: Deletes the last added record from the database.

**Parameters**:
- `Part **parts`: Double pointer to the array of parts.
- `int *count`: Pointer to the count of parts.
- `int *changes`: Pointer to the number of changes.

#### `printNumRecords`
**Purpose**: Prints the total number of part records.

**Parameters**:
- `int count`: The number of parts in the database.

#### `printDatabaseSize`
**Purpose**: Prints the current size of the database in memory.

**Parameters**:
- `int count`: The number of parts in the database.

#### `printNumChanges`
**Purpose**: Prints the total number of changes (additions/deletions) made to the database.

**Parameters**:
- `int *changes`: Pointer to the number of changes.
- `int increment`: Flag to indicate if the change count should be incremented.

### Main Function
**Purpose**: Controls the overall flow of the parts manager program.

**Operations**:
- Checks for the correct number of command-line arguments.
- Initializes variables and allocates initial memory.
- Populates the database with a sample part.
- Main menu loop for user interaction.
- Handles user selections and calls the appropriate functions.
- Frees allocated memory before exiting.
