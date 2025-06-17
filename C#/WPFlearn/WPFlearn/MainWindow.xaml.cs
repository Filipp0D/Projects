using System.Windows;

namespace WPFlearn
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            DataContext = new PersonaViewModel(); // Associa la ViewModel alla UI
        }
    }
}




/*
using System.Windows;

namespace MyApp
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show("Hai cliccato il pulsante!");
        }

        private void Saluta_Click(object sender, RoutedEventArgs e)
        {
            lblSaluto.Content = "Ciao, " + txtNome.Text + "!";
        }
    }
}
*/