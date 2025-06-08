public class MageCharacter extends CharacterBase {
    public MageCharacter(String name, int level) {
        super(name, level, Job.MAGE);
    }

    @Override
    protected void setInitialHpMp() {
        hp = 80;
        mp = 100;
    }

    @Override
    public void levelUp() {
        level++;
        int intelligenceGrowth = 4;
        int luckGrowth = 1;

        intelligence += intelligenceGrowth;
        luck += luckGrowth;

        hp += (strength * 5);
        mp += (intelligenceGrowth * 10);
    }
}
