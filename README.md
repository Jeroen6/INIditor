INIditor
==========
A small tool to help end-users change .ini files in a user friendly graphical way. While still providing documentation for advanced users with text editors.

### Goals
- Provide a Graphical way to edit options in ini files.
- Store key details in a readable way (doxygen-ish) in the ini file itself.
- Use these details for the creation of gui objects.
- Use [Qt](http://qt-project.org/) without platform dependend api's.

#### Future goals
- Provide a way to create an ini file for use in INIditor.

### Challenges
- Dynamic creation of Graphical elements
- Syntax parsing
 
### Todo (or think of)
- Syntax for list selections (to select multiple)

### INIditor syntax (concept)
The tool should read all details for editing an option from the preceding comment line.
Doing this requires a special inditifier telling the line is iniditor data.
The following style is used to document keys.
```
;< format(min,max) : Name to show above the option
;< optional detailed description to show below the option \
;< more descriptio
;< { list }
```
- `format` specifies integer, float or else.
- `(min, max)` is an optional range specifier.
- `:` indicates the start of the short name. This field ends at LF or CR.
- `\` indicates the description continues on the next line.
- `[]` contains special options for a format
- `{}` contains csv list for dropdown

### Example (concept)
.\doc\syntax.ini

















