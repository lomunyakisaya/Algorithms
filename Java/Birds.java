public class Birds {
    Birds(String name, String species){
        this.name = name;
        this.species = species;
    }
    String name;
    String species;
    void peking(){
        System.out.println(name + " of Species:"+ species + " is peking maize on the floor");
    }
}
