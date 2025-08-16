namespace PRACTICA_4
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
            this.txtApellido = new System.Windows.Forms.TextBox();
            this.btnBoton = new System.Windows.Forms.Button();
            this.txtNuevo = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // txtApellido
            // 
            this.txtApellido.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtApellido.Location = new System.Drawing.Point(262, 128);
            this.txtApellido.MaxLength = 20;
            this.txtApellido.Name = "txtApellido";
            this.txtApellido.Size = new System.Drawing.Size(100, 22);
            this.txtApellido.TabIndex = 0;
            this.txtApellido.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txtApellido_KeyPress);
            // 
            // btnBoton
            // 
            this.btnBoton.Location = new System.Drawing.Point(272, 183);
            this.btnBoton.Name = "btnBoton";
            this.btnBoton.Size = new System.Drawing.Size(75, 23);
            this.btnBoton.TabIndex = 1;
            this.btnBoton.Text = "Click";
            this.btnBoton.UseVisualStyleBackColor = true;
            this.btnBoton.Click += new System.EventHandler(this.btnBoton_Click);
            // 
            // txtNuevo
            // 
            this.txtNuevo.Location = new System.Drawing.Point(262, 242);
            this.txtNuevo.Multiline = true;
            this.txtNuevo.Name = "txtNuevo";
            this.txtNuevo.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal;
            this.txtNuevo.Size = new System.Drawing.Size(165, 76);
            this.txtNuevo.TabIndex = 2;
            this.txtNuevo.Leave += new System.EventHandler(this.txtNuevo_Leave);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.txtNuevo);
            this.Controls.Add(this.btnBoton);
            this.Controls.Add(this.txtApellido);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtApellido;
        private System.Windows.Forms.Button btnBoton;
        private System.Windows.Forms.TextBox txtNuevo;
    }
}

