public class ThiefCharacter extends CharacterBase {
    public ThiefCharacter(String name, int level) {
        super(name, level, Job.THIEF);
    }

    @Override
    protected void setInitialHpMp() {
        hp = 100;
        mp = 50;
    }

    @Override
    public void levelUp() {
        level++;
        int luckGrowth = 4;
        int dexterityGrowth = 1;

        luck += luckGrowth;
        dexterity += dexterityGrowth;

        hp += (dexterity * 6);
        mp += (luckGrowth * 6);
    }
}
