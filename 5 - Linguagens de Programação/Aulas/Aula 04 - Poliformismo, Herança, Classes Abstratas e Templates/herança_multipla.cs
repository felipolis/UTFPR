using System;

public interface Car {
  void setModel(string model);
  string getModel();
}

public interface Robot {
  void setWhatDo(string whatDo);
  string getWhatDo();

}

public class Transformer: Car, Robot {
  
  private string _model;
  private string _whatDo;

  public string getModel() { return _model; }
  public string getWhatDo() { return _whatDo; }
  public void setModel(string model) { _model = model; }
  public void setWhatDo(string whatDo) { _whatDo = whatDo; }

  public string Name { get; set; }

  static void Main(string[] args) {
    Transformer t = new Transformer();
    t.setWhatDo("fala pelo rádio");
    t.setModel("New Beatle");
    t.Name = "Bubble Bee";
    Console.WriteLine("Ele {0} e é um {1}... Então é o {2}!",
      t.getWhatDo(), t.getModel(), t.Name);
  }
}