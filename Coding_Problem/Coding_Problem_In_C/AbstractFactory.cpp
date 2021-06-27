class Maze {
public:
	Maze() {}
	void AddRoom(Room*) {}
};
class Room {
public:
	Room(int) {}
};
class EnchantedRoom : public Room {
	EnchantedRoom(int n1, int n2) : Room(n1){ }
};
class Wall {
public:
	Wall() {}
};
class Door {
public:
	Door(Room*, Room*) {}
};
class DoorNeedingSpell : public Door {
	DoorNeedingSpell(Room* r1, Room* r2) : Door(r1,r2) {}
};
// abstract factory
class MazeFactory
{
public:
	MazeFactory();

	virtual Maze* MakeMaze() const { return new Maze; }
	virtual Room* MakeRoom(int n) const { return new Room(n); }
	virtual Wall* MakeWall() const { return new Wall; }
	virtual Door* makeDoor(Room* r1, Room* r2) const { return new Door(r1, r2); }
};

class EnchantedMazeFactory : public MazeFactory {
public:
	EnchantedMazeFactory();

	virtual Room* makeRoom(int n) const {
		return new EnchantedRoom(n, n +1);
	}
	virtual Door* makeDoor(Room* r1, Room* r2) const {
		return new DoorNeedingSpell(r1, r2);
	}

};

// factory method
class MazeGame
{
public:
	Maze* CreateMaze(MazeFactory& factory);

	virtual Maze* MakeMaze() const { 
		return new Maze; }
	virtual Room* MakeRoom(int n) const { 
		return new Room(n); }
	virtual Wall* MakeWall() const { 
		return new Wall; }
	virtual Door* makeDoor(Room* r1, Room* r2) const { 
		return new Door(r1, r2); }
};

Maze * MazeGame::CreateMaze(MazeFactory& factory)
{
	Maze* amaze = factory.MakeMaze();

	Room* r1 = factory.MakeRoom(1);
	Room* r2 = factory.MakeRoom(2);
	Door* theDoor = factory.makeDoor(r1, r2);

	amaze->AddRoom(r1);
	amaze->AddRoom(r2);

	return amaze;
}

int main() {
	MazeGame game;
	// 만들고 싶은 팩토리 객체를 생성후
	EnchantedMazeFactory factory;
	// 인자로 넘긴다.
	game.CreateMaze(factory);
	return 0;
}