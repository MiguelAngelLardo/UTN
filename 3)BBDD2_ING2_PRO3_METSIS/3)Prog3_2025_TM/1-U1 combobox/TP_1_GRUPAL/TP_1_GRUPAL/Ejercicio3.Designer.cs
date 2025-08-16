namespace TP_1_GRUPAL
{
    partial class Ejercicio3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
      this.gbSexo = new System.Windows.Forms.GroupBox();
      this.rbMasculino = new System.Windows.Forms.RadioButton();
      this.rbFemenino = new System.Windows.Forms.RadioButton();
      this.gbEstadoCivil = new System.Windows.Forms.GroupBox();
      this.rbSoltero = new System.Windows.Forms.RadioButton();
      this.rbCasado = new System.Windows.Forms.RadioButton();
      this.clbOficios = new System.Windows.Forms.CheckedListBox();
      this.btnMostrar = new System.Windows.Forms.Button();
      this.lblResultado = new System.Windows.Forms.Label();
      this.gbSexo.SuspendLayout();
      this.gbEstadoCivil.SuspendLayout();
      this.SuspendLayout();
      // 
      // gbSexo
      // 
      this.gbSexo.Controls.Add(this.rbMasculino);
      this.gbSexo.Controls.Add(this.rbFemenino);
      this.gbSexo.Location = new System.Drawing.Point(12, 12);
      this.gbSexo.Name = "gbSexo";
      this.gbSexo.Size = new System.Drawing.Size(118, 79);
      this.gbSexo.TabIndex = 0;
      this.gbSexo.TabStop = false;
      this.gbSexo.Text = "Sexo";
      // 
      // rbMasculino
      // 
      this.rbMasculino.AutoSize = true;
      this.rbMasculino.Location = new System.Drawing.Point(7, 43);
      this.rbMasculino.Name = "rbMasculino";
      this.rbMasculino.Size = new System.Drawing.Size(73, 17);
      this.rbMasculino.TabIndex = 1;
      this.rbMasculino.Text = "Masculino";
      this.rbMasculino.UseVisualStyleBackColor = true;
      // 
      // rbFemenino
      // 
      this.rbFemenino.AutoSize = true;
      this.rbFemenino.Checked = true;
      this.rbFemenino.Location = new System.Drawing.Point(7, 20);
      this.rbFemenino.Name = "rbFemenino";
      this.rbFemenino.Size = new System.Drawing.Size(71, 17);
      this.rbFemenino.TabIndex = 0;
      this.rbFemenino.TabStop = true;
      this.rbFemenino.Text = "Femenino";
      this.rbFemenino.UseVisualStyleBackColor = true;
      // 
      // gbEstadoCivil
      // 
      this.gbEstadoCivil.Controls.Add(this.rbSoltero);
      this.gbEstadoCivil.Controls.Add(this.rbCasado);
      this.gbEstadoCivil.Location = new System.Drawing.Point(182, 12);
      this.gbEstadoCivil.Name = "gbEstadoCivil";
      this.gbEstadoCivil.Size = new System.Drawing.Size(118, 79);
      this.gbEstadoCivil.TabIndex = 1;
      this.gbEstadoCivil.TabStop = false;
      this.gbEstadoCivil.Text = "EstadoCivil";
      // 
      // rbSoltero
      // 
      this.rbSoltero.AutoSize = true;
      this.rbSoltero.Location = new System.Drawing.Point(6, 43);
      this.rbSoltero.Name = "rbSoltero";
      this.rbSoltero.Size = new System.Drawing.Size(58, 17);
      this.rbSoltero.TabIndex = 3;
      this.rbSoltero.Text = "Soltero";
      this.rbSoltero.UseVisualStyleBackColor = true;
      // 
      // rbCasado
      // 
      this.rbCasado.AutoSize = true;
      this.rbCasado.Checked = true;
      this.rbCasado.Location = new System.Drawing.Point(6, 19);
      this.rbCasado.Name = "rbCasado";
      this.rbCasado.Size = new System.Drawing.Size(61, 17);
      this.rbCasado.TabIndex = 2;
      this.rbCasado.TabStop = true;
      this.rbCasado.Text = "Casado";
      this.rbCasado.UseVisualStyleBackColor = true;
      // 
      // clbOficios
      // 
      this.clbOficios.FormattingEnabled = true;
      this.clbOficios.Items.AddRange(new object[] {
            "Data Entry",
            "Operador de PC",
            "Programador",
            "Reparador de PC",
            "Tester"});
      this.clbOficios.Location = new System.Drawing.Point(97, 97);
      this.clbOficios.Name = "clbOficios";
      this.clbOficios.Size = new System.Drawing.Size(128, 94);
      this.clbOficios.TabIndex = 2;
      // 
      // btnMostrar
      // 
      this.btnMostrar.Location = new System.Drawing.Point(72, 197);
      this.btnMostrar.Name = "btnMostrar";
      this.btnMostrar.Size = new System.Drawing.Size(177, 23);
      this.btnMostrar.TabIndex = 3;
      this.btnMostrar.Text = "Mostrar lo que se seleccionó";
      this.btnMostrar.UseVisualStyleBackColor = true;
      this.btnMostrar.Click += new System.EventHandler(this.btnMostrar_Click);
      // 
      // lblResultado
      // 
      this.lblResultado.AutoSize = true;
      this.lblResultado.Location = new System.Drawing.Point(69, 240);
      this.lblResultado.Name = "lblResultado";
      this.lblResultado.Size = new System.Drawing.Size(0, 13);
      this.lblResultado.TabIndex = 4;
      // 
      // Ejercicio3
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(335, 347);
      this.Controls.Add(this.lblResultado);
      this.Controls.Add(this.btnMostrar);
      this.Controls.Add(this.clbOficios);
      this.Controls.Add(this.gbEstadoCivil);
      this.Controls.Add(this.gbSexo);
      this.Name = "Ejercicio3";
      this.Text = "Ejercicio 3";
      this.gbSexo.ResumeLayout(false);
      this.gbSexo.PerformLayout();
      this.gbEstadoCivil.ResumeLayout(false);
      this.gbEstadoCivil.PerformLayout();
      this.ResumeLayout(false);
      this.PerformLayout();

        }

    #endregion

    private System.Windows.Forms.GroupBox gbSexo;
    private System.Windows.Forms.GroupBox gbEstadoCivil;
    private System.Windows.Forms.RadioButton rbFemenino;
    private System.Windows.Forms.RadioButton rbMasculino;
    private System.Windows.Forms.RadioButton rbCasado;
    private System.Windows.Forms.RadioButton rbSoltero;
    private System.Windows.Forms.CheckedListBox clbOficios;
    private System.Windows.Forms.Button btnMostrar;
    private System.Windows.Forms.Label lblResultado;
  }
}