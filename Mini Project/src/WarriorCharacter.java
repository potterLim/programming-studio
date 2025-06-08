public class WarriorCharacter extends CharacterBase {
    public WarriorCharacter(String name, int level) {
        super(name, level, Job.WARRIOR);
    }

    @Override
    protected void setInitialHpMp() {
        hp = 150;
        mp = 30;
    }

    @Override
    public void levelUp() {
        level++;
        int strengthGrowth = 4;
        int dexterityGrowth = 1;

        strength += strengthGrowth;
        dexterity += dexterityGrowth;

        hp += (strengthGrowth * 10);
        mp += (intelligence * 2);
    }
}
