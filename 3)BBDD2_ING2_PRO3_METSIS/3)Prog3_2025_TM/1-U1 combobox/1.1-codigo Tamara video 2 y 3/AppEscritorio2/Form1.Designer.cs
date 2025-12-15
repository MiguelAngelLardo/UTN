namespace AppEscritorio2
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblSeleccioneColor = new System.Windows.Forms.Label();
            this.cbColores = new System.Windows.Forms.ComboBox();
            this.btnAceptar = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblSeleccioneColor
            // 
            this.lblSeleccioneColor.AutoSize = true;
            this.lblSeleccioneColor.Location = new System.Drawing.Point(69, 104);
            this.lblSeleccioneColor.Name = "lblSeleccioneColor";
            this.lblSeleccioneColor.Size = new System.Drawing.Size(136, 17);
            this.lblSeleccioneColor.TabIndex = 0;
            this.lblSeleccioneColor.Text = "Seleccione un color:";
            // 
            // cbColores
            // 
            this.cbColores.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cbColores.FormattingEnabled = true;
            this.cbColores.Location = new System.Drawing.Point(234, 104);
            this.cbColores.Name = "cbColores";
            this.cbColores.Size = new System.Drawing.Size(223, 24);
            this.cbColores.TabIndex = 1;
            // 
            // btnAceptar
            // 
            this.btnAceptar.Location = new System.Drawing.Point(488, 89);
            this.btnAceptar.Name = "btnAceptar";
            this.btnAceptar.Size = new System.Drawing.Size(114, 46);
            this.btnAceptar.TabIndex = 2;
            this.btnAceptar.Text = "Aceptar";
            this.btnAceptar.UseVisualStyleBackColor = true;
            this.btnAceptar.Click += new System.EventHandler(this.btnAceptar_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 240);
            this.Controls.Add(this.btnAceptar);
            this.Controls.Add(this.cbColores);
            this.Controls.Add(this.lblSeleccioneColor);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblSeleccioneColor;
        private System.Windows.Forms.ComboBox cbColores;
        private System.Windows.Forms.Button btnAceptar;
    }
}

