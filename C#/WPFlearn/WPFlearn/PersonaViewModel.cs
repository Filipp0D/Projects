using System.ComponentModel;
using System.Windows.Input;

namespace WPFlearn
{
    public class PersonaViewModel : INotifyPropertyChanged
    {
        private string _nome;
        public string Nome
        {
            get { return _nome; }
            set
            {
                _nome = value;
                OnPropertyChanged(nameof(Nome)); // Notifica la UI del cambiamento
            }
        }

        // Comando per stampare un saluto
        public ICommand SalutaCommand { get; }

        public PersonaViewModel()
        {
            SalutaCommand = new RelayCommand(Saluta);
        }

        private void Saluta()
        {
            Nome = "Ciao, " + Nome;
        }

        // Implementazione di INotifyPropertyChanged
        public event PropertyChangedEventHandler PropertyChanged;
        protected void OnPropertyChanged(string propertyName)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
