public abstract class CharacterBase {
    protected String name;
    protected int level;
    protected int hp;
    protected int mp;
    protected Job job;
    protected int strength;
    protected int dexterity;
    protected int intelligence;
    protected int luck;

    public CharacterBase(String name, int level, Job job) {
        if (level < 1) {
            level = 1;
        }

        this.name = name;
        this.job = job;
        this.level = 1;
        this.strength = 4;
        this.dexterity = 4;
        this.intelligence = 4;
        this.luck = 4;

        setInitialHpMp();

        for (int i = 1; i < level; i++) {
            levelUp();
        }
    }

    protected abstract void setInitialHpMp();

    public void setLevel(int newLevel) {
        if (newLevel < 1) {
            newLevel = 1;
        }

        level = 1;
        strength = 4;
        dexterity = 4;
        intelligence = 4;
        luck = 4;

        setInitialHpMp();

        for (int i = 1; i < newLevel; i++) {
            levelUp();
        }
    }

    public void displayDetails() {
        System.out.printf("%-15s: %s%n", "Name", name);
        System.out.printf("%-15s: %s%n", "Job", job);
        System.out.printf("%-15s: %d%n", "Level", level);
        System.out.printf("%-15s: %d%n", "Strength", strength);
        System.out.printf("%-15s: %d%n", "Dexterity", dexterity);
        System.out.printf("%-15s: %d%n", "Intelligence", intelligence);
        System.out.printf("%-15s: %d%n", "Luck", luck);
        System.out.printf("%-15s: %d%n", "HP", hp);
        System.out.printf("%-15s: %d%n", "MP", mp);
    }


    public void displaySummary() {
        System.out.printf("%-15s %-10s %-5d%n", name, job, level);
    }

    public String getName() {
        return name;
    }

    public int getLevel() {
        return level;
    }

    public int getHp() {
        return hp;
    }

    public int getMp() {
        return mp;
    }

    public Job getJob() {
        return job;
    }

    public int getStrength() {
        return strength;
    }

    public int getDexterity() {
        return dexterity;
    }

    public int getIntelligence() {
        return intelligence;
    }

    public int getLuck() {
        return luck;
    }

    public abstract void levelUp();
}
