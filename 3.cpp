#include<iostream>
using namespace std;
#include<string>

class Spaceship
{
public:
    int model;
    int speed;
    int energy;
public:
    virtual void showStats() {
        cout << this->model << endl;
        cout << this->speed << endl;
        cout << this->energy << endl;
    }
public:
    virtual void action() = 0;
    virtual string getType() = 0;
};

class CargoShip :public Spaceship
{
public:
    int cargoCapacity;
public:
    CargoShip(int m = 1001, int s = 50, int e = 100, int cap = 500) {
        model = m;
        speed = s;
        energy = e;
        cargoCapacity = cap;
    }

    virtual void action() {
        cout << "运输飞船正在装载货物" << endl;
    }

    virtual string getType() {
        return "CargoShip";
    }

public:
    void loadCargo(int cargo)
    {
        if (cargo <= cargoCapacity) {
            cargoCapacity -= cargo;
            cout << cargo << endl;
            cout << cargoCapacity << endl;
        }
        else {
            cout << cargoCapacity << endl;
        }
    }
};

class BattleShip :public Spaceship
{
public:
    int weaponpower;
    int laserCost;
public:
    BattleShip(int m = 2001, int s = 80, int e = 150, int wp = 50, int cost = 10) {
        model = m;
        speed = s;
        energy = e;
        weaponpower = wp;
        laserCost = cost;
    }

    virtual void action() {
        cout << "战斗飞船即将发射激光" << endl;
    }

    virtual string getType() {
        return "BattleShip";
    }

public:
    void fireLaser() {
        if (energy >= laserCost) {
            energy -= laserCost;
            cout << weaponpower << endl;
            cout << energy << endl;
        }
        else {
            cout << laserCost << endl;
        }
    }
};

class ExplorerShip :public Spaceship
{
public:
    int scanRange;
    int scanCost;
public:
    ExplorerShip(int m = 3001, int s = 60, int e = 120, int range = 100, int cost = 5) {
        model = m;
        speed = s;
        energy = e;
        scanRange = range;
        scanCost = cost;
    }

    virtual void action()
    {
        cout << "探索飞船正在扫描星球" << endl;
    }

    virtual string getType() {
        return "ExplorerShip";
    }

    void scanPlanet()
    {
        int count = 0;
        while (energy >= scanCost) {
            energy -= scanCost;
            count++;
            cout << count << endl;
            cout << scanRange << endl;
            cout << energy << endl;

            if (energy < scanCost) {
                cout << "能量不足，扫描结束" << endl;
                break;
            }

            cout << "1-继续, 0-停止";
            int continueScan;
            cin >> continueScan;
            if (continueScan == 0) {
                break;
            }
        }
    }
};

class SpaceshipFleet
{
private:
    static const int MAX_SHIPS = 100;
    Spaceship* myShips[MAX_SHIPS];
    Spaceship* rentedShips[MAX_SHIPS];
    int myShipCount;
    int rentedShipCount;

public:
    SpaceshipFleet() {
        myShipCount = 0;
        rentedShipCount = 0;
        for (int i = 0; i < MAX_SHIPS; i++) {
            myShips[i] = nullptr;
            rentedShips[i] = nullptr;
        }
    }

    ~SpaceshipFleet() {
        for (int i = 0; i < myShipCount; i++) {
            delete myShips[i];
        }
        for (int i = 0; i < rentedShipCount; i++) {
            delete rentedShips[i];
        }
    }

    void rentSpaceship(Spaceship* ship) {
        if (rentedShipCount < MAX_SHIPS) {
            rentedShips[rentedShipCount] = ship;
            rentedShipCount++;
            cout << "租赁成功！" << endl;
        }
        else {
            cout << "租赁飞船库已满！" << endl;
            delete ship;
        }
    }

    void buySpaceship(Spaceship* ship) {
        if (myShipCount < MAX_SHIPS) {
            myShips[myShipCount] = ship;
            myShipCount++;
            cout << "购买成功！" << endl;
        }
        else {
            cout << "我的飞船库已满！" << endl;
            delete ship;
        }
    }

    void showAllShips() {
        int cargoCount = 0, battleCount = 0, explorerCount = 0;

        for (int i = 0; i < myShipCount; i++) {
            if (myShips[i]->getType() == "CargoShip") cargoCount++;
            else if (myShips[i]->getType() == "BattleShip") battleCount++;
            else if (myShips[i]->getType() == "ExplorerShip") explorerCount++;
        }

        for (int i = 0; i < rentedShipCount; i++) {
            if (rentedShips[i]->getType() == "CargoShip") cargoCount++;
            else if (rentedShips[i]->getType() == "BattleShip") battleCount++;
            else if (rentedShips[i]->getType() == "ExplorerShip") explorerCount++;
        }

        cout << cargoCount << endl;
        cout << battleCount << endl;
        cout << explorerCount << endl;
        cout << myShipCount << endl;
        cout << rentedShipCount << endl;
    }

    int getMyShipCount() {
        return myShipCount;
    }

    int getRentedShipCount() {
        return rentedShipCount;
    }
};

Spaceship* createSpaceship(int type) {
    int model, speed, energy;

    cin >> model;
    cin >> speed;
    cin >> energy;

    if (type == 1) {
        int capacity;
        cin >> capacity;
        return new CargoShip(model, speed, energy, capacity);
    }
    else if (type == 2) {
        int power, cost;
        cin >> power;
        cin >> cost;
        return new BattleShip(model, speed, energy, power, cost);
    }
    else if (type == 3) {
        int range, cost;
        cin >> range;
        cin >> cost;
        return new ExplorerShip(model, speed, energy, range, cost);
    }

    return nullptr;
}

void showMenu() {
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
}

void showShipTypes() {
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
}

void rentSpaceship(SpaceshipFleet& fleet) {
    showShipTypes();
    int choice;
    cin >> choice;

    Spaceship* ship = nullptr;

    switch (choice) {
    case 1: {
        ship = new CargoShip();
        CargoShip* cargoShip = dynamic_cast<CargoShip*>(ship);
        cargoShip->action();
        int cargo;
        cin >> cargo;
        cargoShip->loadCargo(cargo);
        break;
    }
    case 2: {
        ship = new BattleShip();
        BattleShip* battleShip = dynamic_cast<BattleShip*>(ship);
        battleShip->action();
        battleShip->fireLaser();
        break;
    }
    case 3: {
        ship = new ExplorerShip();
        ExplorerShip* explorerShip = dynamic_cast<ExplorerShip*>(ship);
        explorerShip->action();
        explorerShip->scanPlanet();
        break;
    }
    default:
        cout << "无效选择！" << endl;
        return;
    }

    if (ship != nullptr) {
        fleet.rentSpaceship(ship);
    }
}

void buySpaceship(SpaceshipFleet& fleet) {
    showShipTypes();
    int choice;
    cin >> choice;

    Spaceship* ship = createSpaceship(choice);
    if (ship != nullptr) {
        fleet.buySpaceship(ship);
        ship->showStats();
    }
    else {
        cout << "创建飞船失败！" << endl;
    }
}

int main() {
    SpaceshipFleet fleet;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            rentSpaceship(fleet);
            break;
        case 2:
            buySpaceship(fleet);
            break;
        case 3:
            fleet.showAllShips();
            break;
        case 4:
            cout << "感谢使用星际飞船管理系统！" << endl;
            break;
        default:
            cout << "无效选择，请重新输入！" << endl;
        }
    } while (choice != 4);

    return 0;
}     