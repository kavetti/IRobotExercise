
# Toy Robot Challenge
The application is a simulation of a toy robot moving on a square dimension of 5 units x 5 units. There
are no distructions on the table surface. But must be prevented from falling to destruction. Any movement that would result in the robot from falling the table must be prevented. However any further valid movement must be allowed.

## Installation
ToyRobotChallenge.exe is a console application. This accepts commands so that the robot moves within the table.
Copy the Executable to your desired directory and run the application.

## Usage
Open a command prompt and type ToyRobotChallenge.exe. This will show a command prompt to accept the message.
Commands Available for use are:<BR>
<B>HELP</B> - Displays this Message<BR>
<B>EXIT</B> - To End this Game<BR>
<B>PLACE</B> - To Set the Toy on the Table<BR>
<T>Format: PLACE X,Y,DIRECTION <BR>
Where<BR>
X is the X Position From WEST to EAST. Maximum Position is 5<BR>
Y is the Y Position From SOUTH to NORTH. Maximum Position is 5<BR>
DIRECTION is the direction of the Move. N - North, S - South, E - East , W - West<BR>
<B>MOVE</B> - Move the Robot as identified by DIRECTION <BR>
<B>LEFT</B> - Change DIRECTION Counter Clockwise <BR>
<B>RIGHT</B> - Change DIRECTION Clockwise <BR>
<B>REPORT</B> - Display the Current Position and Direction <BR>

## Contributing
1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D
