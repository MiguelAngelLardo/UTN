namespace AppEscritorio2
{
    partial class Form2
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
            this.label1 = new System.Windows.Forms.Label();
            this.txtNombres = new System.Windows.Forms.TextBox();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.lbPersonas = new System.Windows.Forms.ListBox();
            this.btnMostrarSeleccionado = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(52, 53);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(118, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Ingrese nombres:";
            // 
            // txtNombres
            // 
            this.txtNombres.Location = new System.Drawing.Point(205, 53);
            this.txtNombres.Name = "txtNombres";
            this.txtNombres.Size = new System.Drawing.Size(257, 22);
            this.txtNombres.TabIndex = 1;
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(495, 46);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(81, 31);
            this.btnAceptar.TabIndex = 2;
            this.btnAceptar.Text = "Aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            this.btnAceptar.Click += new System.EventHandler(this.btnAceptar_Click);
            // 
            // lbPersonas
            // 
            this.lbPersonas.FormattingEnabled = true;
            this.lbPersonas.ItemHeight = 16;
            this.lbPersonas.Location = new System.Drawing.Point(131, 117);
            this.lbPersonas.Name = "lbPersonas";
            this.lbPersonas.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.lbPersonas.Size = new System.Drawing.Size(395, 212);
            this.lbPersonas.TabIndex = 3;
            // 
            // btnMostrarSeleccionado
            // 
            this.btnMostrarSeleccionado.Location = new System.Drawing.Point(552, 274);
            this.btnMostrarSeleccionado.Name = "btnMostrarSeleccionado";
            this.btnMostrarSeleccionado.Size = new System.Drawing.Size(121, 55);
            this.btnMostrarSeleccionado.TabIndex = 4;
            this.btnMostrarSeleccionado.Text = "Mostrar seleccionado";
            this.btnMostrarSeleccionado.UseVisualStyleBackColor = true;
            this.btnMostrarSeleccionado.Click += new System.EventHandler(this.btnMostrarSeleccionado_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnMostrarSeleccionado);
            this.Controls.Add(this.lbPersonas);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.txtNombres);
            this.Controls.Add(this.label1);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtNombres;
        private System.Windows.Forms.Button btnAceptar;
        private System.Windows.Forms.ListBox lbPersonas;
        private System.Windows.Forms.Button btnMostrarSeleccionado;
    }
}