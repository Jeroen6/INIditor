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
```
- `format` specifies integer, float or else.
- `(min, max)` is an optional range specifier.
- `:` indicates the start of the short name. This field ends at LF or CR.
- `\` indicates the description continues on the next line.
- `[]` contains special options for a format

### Example (concept)
```
;< Section description with basic format examples
[Basic formats]

;< integer(0,5) : Wait for user (seconds)
;< A value between 0 and 5.
waitUser=2

;< string(5,32)[A-Za-z0-9] : Your  username
;< this key requires a 5 to 32 character string with only alphanumerical characters
username=Jeroen6

;< float(-1,1)[3] : Floating point value
;< Enter a floating point value between -1 and 1 with 3 decimal places
value=0.678

;< Section description with date/time format examples
[Time formats]
;iso8601, no local formats allowed.

;< date(2000-1-1, 2020-12-31) : First login date
;< day first logged in
firstDay=2014-8-16

;< time(06:00, 18:00) : First login time
;< Time first logged in
firstTime=12:26:33
; notice there is no timezone

;< timestamp(2000-1-1, 2020-12-31) : First login timestamp
;< Time first logged in
firstTimeStamp=2014-08-16T12:26:32+00:00
; notice there are no milliseconds, the min or max can also be a full iso8601 timestamp as in firstTimeStamp

;< Section for other formats
[more formats]

;< dropdown : mode of operation
;< Choose a mode of operation
;< (0)off, (1)neutral, (2)passive, (3)active
mode=0

;< dropdown : mode of operation
;< Choose a mode of operation
;< (100)off, (285)neutral, (756)passive, (234)active
mode=756

;< dropdown : mode of operation
;< Choose a mode of operation
;< off, neutral, passive, active
stringmode=neutral

;< radio : mode of operation
;< Choose a mode of operation
;< off, neutral, passive, active
stringmode=neutral

;< bool : Enable self destruct on case-open
;< Have the device act as smokemachine when the case is opened.
allowselfdestuct=0
; tickbox with tick or no tick

;< bool(2) : Enable self destruct on case-open
;< Have the device act as smokemachine when the case is opened.
allowselfdestuct=0
; tickbox with tick, no tick, and semi-tick (the square state)

















