public class ArcherCharacter extends CharacterBase {
    public ArcherCharacter(String name, int level) {
        super(name, level, Job.ARCHER);
    }

    @Override
    protected void setInitialHpMp() {
        hp = 110;
        mp = 60;
    }

    @Override
    public void levelUp() {
        level++;
        int dexterityGrowth = 4;
        int strengthGrowth = 1;

        dexterity += dexterityGrowth;
        strength += strengthGrowth;

        hp += (dexterityGrowth * 8);
        mp += (intelligence * 5);
    }
}
