#pragma once
class World
{
public:
	

	private:
		int golds;
		int rocks;
		int wood;
		int freeWorkers;
		int goldWorkers;
		int rockWorkers;
		int woodWorkers;
	public:
		int getGolds() const;
		void setGolds(int golds);
		int getRocks() const;
		void setRocks(int rocks);
		int getWood() const;
		void setWood(int wood);
		int getWorkers() const;
		void setWorkers(int workers);


		World(int golds, int rocks, int wood, int freeWorkers, int goldWorkers, int rockeWorkers, int woodWorkers);

		World();
		~World();
};

