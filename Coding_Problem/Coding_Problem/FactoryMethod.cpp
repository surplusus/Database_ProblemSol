class Maze {
public:
	Maze() {}
	void AddRoom(Room*) {}
};
class Room {
public:
	Room(int){}
};
class Wall {
public:
	Wall() {}
};
class Door {
public:
	Door(Room*, Room*) {}
};
class MazeGame
{
public:
	Maze* CreateMaze();

	virtual Maze* MakeMaze() const { return new Maze; }
	virtual Room* MakeRoom(int n) const { return new Room(n); }
	virtual Wall* MakeWall() const { return new Wall; }
	virtual Door* makeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

Maze * MazeGame::CreateMaze()
{
	Maze* amaze = MakeMaze();

	Room* r1 = MakeRoom(1);
	Room* r2 = MakeRoom(2);
	Door* theDoor = makeDoor(r1, r2);

	amaze->AddRoom(r1);
	amaze->AddRoom(r2);

	return amaze;
}

struct BombedWall : public Wall{
	BombedWall() {}
};
struct RoomWithBomb : public Room {
	RoomWithBomb(int n) : Room(n) {}
};
class BombedMazeGame : public MazeGame
{
public:
	BombedMazeGame() {}

	virtual Wall* MakeWall() const {
		return new BombedWall;
	}
	virtual Room* MakeRoom(int n) const {
		return new RoomWithBomb(n);
	}
};